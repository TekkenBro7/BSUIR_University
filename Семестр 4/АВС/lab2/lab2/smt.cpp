#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <sched.h>
#include <thread>
#include <mutex>

using std::cin, std::cout, std::endl;

std::mutex mtx;

void calculate(std::fstream& file1, std::fstream& file2, double a, double b, double h, double e, int& iterations, double& time) {
    double Y, S, x, n, buff;
    double k, fact;
    constexpr double up = 10000000;
    double zero = 0, one = 1, exp = 2.71828182846, two = 2;
    int iter = 0;
    for (x = a; x <= b; ) {
        Y = (1+2*x*x)*pow(exp,x*x);
        k = 1;
        n = 1;
        S = 1;
        fact=1;
        auto start = std::chrono::high_resolution_clock::now();
        asm (
            "y_loop:"
             // x^(2k)
            "fldl %0;" 
            "fmull %1;"     
            "fmull %1;"
            "fstpl %0;"
            //k!
            "fldl %2;"
            "fmull %7;"
            "fstpl %7;"
            //2k+1
            "fldl %2;"
            "fmull %5;"
            "faddl %6;"
            // (2k+1)*(x^(2k))/k!
            "fmull %0;"
            "fdivl %7;"
            // add to S(x)
            "faddl %3;"
            "fstpl %3;"
            // k++
            "fldl %2;"
            "faddl %6;"
            "fstpl %2;"
            // check if we can get specified precision
            "fldl %2;"
            "fcoml %8;"
            "fstsw %%ax;"
            "sahf;"
            "ja skip;"
            "jmp calc_ok;"
            "skip:"
            : "=m" (k), "=m" (x), "=m" (n), "=m" (S), "=m" (zero), "=m" (two), "=m" (one), "=m" (fact)
            : "m" (up)
        );
        cout << std::setprecision(13) << "Couldn't calculate S(" << x << ")" << "\t\tY(" << x << ") = " << std::setprecision(13) << Y << "\n";
        asm (
            "jmp y_end;"
            "fstpl %0;"
            "calc_ok:"
            "fstpl %0" 
            : "=m" (buff)
        );
        if (fabs(Y - S) < e) {
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed_nanosecs = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            mtx.lock();
            file1 << std::defaultfloat << std::setprecision(12) << Y << "\t\t" << S << "\t\t\t" << std::fixed << std::setprecision(0) << n << "\t\t\t" << std::to_string(elapsed_nanosecs.count()) << "\n";
            iterations += n;
            iter += n;
            time+=elapsed_nanosecs.count();
            file2 << "\nIterations: " << iter << "\nTime elapsed: " << time << "\n";
            mtx.unlock();
            asm (
                "jmp y_end;"
            );
        }

        asm (
            "jmp y_loop;"
            "y_end:"
            "fldl %0;"
            "faddl %1;"
            "fstpl %0;" 
            : "=m" (x) 
            : "m" (h)
        );
    }
}

int main() {
  
    std::fstream file1, file2, file3, file4, file5, file6, file7, file8, file9, file10, file11, file12, file13;
    file1.open("output/smt/smt.txt", std::ios::out);
    file2.open("output/smt/smt_iter1.txt", std::ios::out);
    file3.open("output/smt/smt_iter2.txt", std::ios::out);
    file4.open("output/smt/smt_iter3.txt", std::ios::out);
    file5.open("output/smt/smt_iter4.txt", std::ios::out);
    file6.open("output/smt/smt_iter5.txt", std::ios::out);
    file7.open("output/smt/smt_iter6.txt", std::ios::out);
    file8.open("output/smt/smt_iter7.txt", std::ios::out);
    file9.open("output/smt/smt_iter8.txt", std::ios::out);
    file10.open("output/smt/smt_iter9.txt", std::ios::out);
    file11.open("output/smt/smt_iter10.txt", std::ios::out);
    file12.open("output/smt/smt_iter11.txt", std::ios::out);
    file13.open("output/smt/smt_iter12.txt", std::ios::out);
    file1 << "S\t\t\t\t\tY\t\t\t\t\titerations\t\ttime\n";
    int iterations = 0;
    double a = 0.8, b = 0.85, h = 0.0001, e = 1e-11, time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0, time6 = 0, time7 = 0, time8 = 0, time9 = 0, time10 = 0, time11 = 0, time12 = 0;
    double step = (b - a)/12;
    auto start = std::chrono::high_resolution_clock::now();

    std::thread t1(calculate, std::ref(file1), std::ref(file2), a, a+step, h, e, std::ref(iterations), std::ref(time1));
    std::thread t2(calculate, std::ref(file1), std::ref(file3), a+step, a+2*step, h, e, std::ref(iterations), std::ref(time2));
    std::thread t3(calculate, std::ref(file1), std::ref(file4), a+2*step, a+3*step, h, e, std::ref(iterations), std::ref(time3));
    std::thread t4(calculate, std::ref(file1), std::ref(file5), a+3*step, a+4*step, h, e, std::ref(iterations), std::ref(time4));
    std::thread t5(calculate, std::ref(file1), std::ref(file6), a+4*step, a+5*step, h, e, std::ref(iterations), std::ref(time5));
    std::thread t6(calculate, std::ref(file1), std::ref(file7), a+5*step, a+6*step, h, e, std::ref(iterations), std::ref(time6));
    std::thread t7(calculate, std::ref(file1), std::ref(file8), a+6*step, a+7*step, h, e, std::ref(iterations), std::ref(time7));
    std::thread t8(calculate, std::ref(file1), std::ref(file9), a+7*step, a+8*step, h, e, std::ref(iterations), std::ref(time8));
    std::thread t9(calculate, std::ref(file1), std::ref(file10), a+8*step, a+9*step, h, e, std::ref(iterations), std::ref(time9));
    std::thread t10(calculate, std::ref(file1), std::ref(file11), a+9*step, a+10*step, h, e, std::ref(iterations), std::ref(time10));
    std::thread t11(calculate, std::ref(file1), std::ref(file12), a+10*step, a+11*step, h, e, std::ref(iterations), std::ref(time11));
    std::thread t12(calculate, std::ref(file1), std::ref(file13), a+11*step, b, h, e, std::ref(iterations), std::ref(time12));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();

    file1.close();
    file2.close();
    double time = time1 + time2 + time3 + time4 + time5 + time6 + time7 + time8 + time9 + time10 + time11 + time12;
    cout << "\nIterations: " << iterations << "\nTime elapsed: " << time << endl;
    return 0;
}