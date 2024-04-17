// Пользовательская функция
    fun greet(name: String) {
        println("Привет, $name!")
    }

fun factorial(n: Int): Int {
    return if (n == 0) 1 else n * factorial(n - 1)
}

fun main() {
    // Целочисленные типы
    val byteValue: Byte = 10
    val shortValue: Short = 100
    var intValue: Int = 1000
    val longValue: Long = 100000L
    intValue++
    var name = "Maxim"

    if (intValue == 1)
    {
    	val n = factorial(1337)    
    }
   
    
    var Count = -1

    do {
        println("Count: $Count")
        Count++
    } while (Count < 5)  

     
    val wordCounts = mapOf(
        "apple" to 5,
        "banana" to 3,
        "orange" to 2
    )

    val str = "banana"

    // Проверяем, содержится ли строка в качестве ключа в map
    val count = wordCounts[str]
    if (count != null) {
        println("$str найдено в map. Значение: $count")
    } else {
        println("$str не найдено в map.")
    }

    // Простой цикл for
    for (i in 1..5) {
        println("Значение: $i")
		intValue = 4 / 6;
    }

	 val num = 29
    var flag = false
    for (i in 2..num / 2) {
        // condition for nonprime number
        if (num % i == 0) {
            flag = true
            break
        }
    }
 
    if (!flag)
        println("$num is a prime number.")
    else
        println("$num is not a prime number.")

    // Вещественные типы
    val floatValue: Float = 10.5f
    val doubleValue: Double = 3.14159

    // Логический тип
    val booleanValue: Boolean = true

    // Символьный тип
    val charValue: Char = 'A'

    // Строковый тип
    val stringValue: String = "Hello, Kotlin!"

    // Массивы
    val intArray: Array<Int> = arrayOf(1, 2, 3, 4, 5)
    val stringArray: Array<String> = arrayOf("apple", "banana", "orange")

    // Null-безопасные типы
    val nullableValue: String? = null
	intValue = 23 + 228
   
    val n = 10
    var t1 = 0
    var t2 = 1
    
    print("First $n terms: ")
 
    for (i in 1..n) {
        print("$t1 + ")
 
        val sum = t1 + t2
        t1 = t2
        t2 = sum
    }
    println()

    val a = 10
    var b = 5

   
    // Простой цикл  for
    for (i in 1..5) {
        println("Значение: $i")
	intValue = 4 / 6;
    }

    // Условные конструкции if..else
    if (true) {
        println("a > b")
    } else {
        println("a <= b")
    }

    // Циклы for
    for (i in 1..10) {
        println("Значение i: $i")
    }

    // Цикл do..while
    Count = 0
    do {
        println("Значение Count: $Count")
        Count++
    } while (Count < 5)

    // Цикл while
    var x = 0
    while (x < 5) {
        println("Значение x: $x")
        x++
    }

    // Вызов пользовательской функции
    greet("Мир")

   
    
    val sequenceA = mutableListOf<Int>()
    for (i in -6..30) {
        sequenceA.add(i)
    }
    
    val arrayB = IntArray(30)
    var index = 0
    for (i in sequenceA) {
        if (i < 0 && i % 2 == 0) {
            arrayB[index] = i
        }
        index++
    }
    
    
    
    val array = arrayOf(1, 2, 3, 4, 5)

    for (i in 0 until array.size) {
        for (j in 0 until array.size) {
            for (k in 0 until array.size) {
                for (l in 0 until array.size) {
                    for (m in 0 until array.size) {
                        if (array[i] > 2 && array[j] < 4 && array[k] == 3) {
                            if (array[l] >= 1 && array[m] <= 5) {
                                for (m in 0 until array.size) {
                                    if() {
                                        
                                    }
                                    else if() {
                                    }
                                }
                                println("i: $i, j: $j, k: $k, l: $l, m: $m")
                            }
                        }
                    }
                }
            }
        }
    }

	 for (i in 0 until array.size) {
        for (j in 0 until array.size) {
            for (k in 0 until array.size) {
                if (array[i] > 2) {
                    if (array[j] < 4) {
                        if (array[k] == 3) {
                            println("i: $i, j: $j, k: $k")
                        } else {
                            println("k is not 3")
                        }
                    } else {
                        println("j is not less than 4")
                    }
                } else {
                    println("i is not greater than 2")
                }
            }
        }
    }

    
    val filteredArrayB = arrayB.filter { it != 0 }
    val zeroCount = 30 - filteredArrayB.size
    for (i in 0 until zeroCount) {
        filteredArrayB.plus(0)
    }

    println("Исходная последовательность чисел А1, А2, ..., А30:")
    println(sequenceA)
    println("\nМассив В (значения отрицательных четных чисел):")
    println(filteredArrayB)
}