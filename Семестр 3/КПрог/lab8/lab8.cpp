#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

short n = 0, m = 0, row = 0, column = 0, back_color = 0, text_color = 15, color = 0;
char macro_list[130] = "Macro s+d: PC Speaker signal 1\nMacro s+c: Change text color 2\nMacro s+b: Change background color\nMacro ESC: Exit programm...\n";
FILE* file = fopen("logs.txt", "w");

extern "C" void FUNCTION_LIST(char* list, short length);
extern "C" short KEYS();
extern "C" unsigned char NEXT_KEY();

void log(FILE* file, const char* format, ...) 
{
    time_t currentTime;
    time(&currentTime);
    struct tm* timeInfo = localtime(&currentTime);
    char timeString[9];
    strftime(timeString, sizeof(timeString), "%H.%M.%S", timeInfo);
    fprintf(file, "[%s]: ", timeString);

    va_list args;
    va_start(args, format);
    vfprintf(file, format, args);
    va_end(args);

    fprintf(file, "\n");
}

void checkKeyPress() 
{
    if (file == NULL) 
    {
        printf("Failed to open logs.txt\n");
        return;
    }
    //   unsigned char key;
    //    unsigned char key2;
    short keys = KEYS();
    short key = keys & 0xFF;
    short key2 = keys >> 8;
        if (key2 == 1)
        {
            log(file, "Exit...");
            fclose(file);
            exit(0);
        }
    if (key2 == 59) 
    {
        FUNCTION_LIST(macro_list, strlen(macro_list));
        log(file, "'F1' pressed");
    }

    else if (key == 115 || key == 83) {  // s
        // Получение кода следующей нажатой клавиши
        unsigned char nextKey;
        nextKey = NEXT_KEY();

   //     asm{
    //        mov ah, 0
    //        int 16h
    //        mov nextKey, al
     // }
            if (nextKey == 100 || nextKey == 68) {  // d
                log(file, "'s' + 'd' combination pressed");
                int replay_nummber = 40;
            generate_sound:
                replay_nummber--;
                asm{
                    in al, 61h
                    or al, 2
                    out 61h, al
                }
                int x = 1;
                for (int i = 0; i < 1000; i++) {
                    x = i * i;
                }
                asm{
                    in al, 61h
                    and al, 11111100b
                    out 61h, al
                    mov cx,replay_nummber
                    loop generate_sound
                }
            }

            else if (nextKey == 99 || nextKey == 67 || nextKey == 66 || nextKey == 98) {  // c || b
                if (nextKey == 99 || nextKey == 67) {


                    if (text_color == 6 && back_color == 0) {
                        text_color = 15;
                        color = 15;
                    }
                    else if (text_color == 6 && back_color == 3) {
                        text_color = 15;
                        color = 63;
                    }
                    else if (text_color == 15 && back_color == 3) {
                        text_color = 6;
                        color = 54;
                    }
                    else if (text_color == 15 && back_color == 0) {
                        text_color = 6;
                        color = 6;
                    }
                    log(file, "'s' + 'c' combination pressed. Color of text: %d", text_color);
                }

                //
                else {
                    if (back_color == 0 && text_color == 15) {
                        back_color = 3;
                        color = 63;
                    }
                    else if (back_color == 0 && text_color == 6) {
                        back_color = 3;
                        color = 54;
                    }
                    else if (back_color == 3 && text_color == 15) {
                        back_color = 0;
                        color = 15;
                    }
                    else if (back_color == 3 && text_color == 6) {
                        back_color = 0;
                        color = 6;
                    }
                    log(file, "'s' + 'b' combination pressed. Color of background: %d", back_color);

                }

                asm{
        mov ah, 03h
     mov bh, 0
     int 10h

     mov byte ptr n, dh
     mov byte ptr m, dl

     mov byte ptr row, 0
     mov byte ptr column, 0
                }
                color_text_loop:
                asm{
                    mov ah, 02h
                    mov bh, 0
                    mov dh, byte ptr row
                    mov dl, byte ptr column
                    int 10h

                    mov ah, 08h
                    mov bh, 0
                    int 10h

                    mov ah, 09h
                    mov bh, 0
                    mov bl, byte ptr color
                    mov cx, 1
                    int 10h

                    inc byte ptr column
                    cmp byte ptr column, 80
                    jge __next_row

                    jmp color_text_loop
                }
                __next_row:
                asm{
                    inc byte ptr row
                    mov byte ptr column, 0
                    cmp byte ptr row, 25
                    jl color_text_loop

                    mov ah, 02h
                    mov bh, 0
                    mov dh, byte ptr n
                    mov dl, byte ptr m
                    int 10h
                }

            }
    }
}

int main() {

    while (1) {
        checkKeyPress();
    }

    fclose(file);
    return 0;
}