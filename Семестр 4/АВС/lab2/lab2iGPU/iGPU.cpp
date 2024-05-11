#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <cmath>
#define CL_TARGET_OPENCL_VERSION 300
#include <CL/cl.h>

const std::string programSource = R"(
	#pragma OPENCL EXTENSION cl_khr_fp64 : enable
    __kernel void countSum(__global double* result, __global int* iterations, const double x, const double tolerance, const double real_value, const int iter) {
        int gid = get_global_id(0);
		double sum = 0;
    	double factorial = 1;
    	double power = 1;
		int k = 0;
		for(; k <= iter; k++) {
			double term = (2.0*k + 1) / factorial * power;
			sum += term;
			if(real_value - sum < tolerance || sum - real_value > tolerance){
				break;
			}
			// Обновление значений для следующей итерации
			factorial *= (k + 1);
			power *= x*x;
		}
		iterations[gid] = k;
        result[gid] = sum;
    }
)";

int main() {
	double a = 0.8, b = 0.85, h = 0.0001, tolerance = 1e-11;

    std::ofstream logfile("LOGS.txt"); // Файл для записи результатов

    // Получение доступных платформ
    cl_platform_id platform;
	clGetPlatformIDs(1, &platform, nullptr);

    // Получение доступных устройств
    cl_device_id device;
	clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, nullptr);

    // Создание контекста и очереди команд
    cl_context context = clCreateContext(nullptr, 1, &device, nullptr, nullptr, nullptr);
	cl_command_queue queue = clCreateCommandQueueWithProperties(context, device, 0, nullptr);

    // Создание программы и её компиляция
    cl_program program = clCreateProgramWithSource(context, 1, (const char**)&programSource, nullptr, nullptr);
	auto err = clBuildProgram(program, 1, &device, nullptr, nullptr, nullptr);
	if (err != CL_SUCCESS) {
    	size_t len;
    	char buffer[2048];
    	clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
    	std::cerr << "Ошибка при сборке программы: " << err << std::endl;
    	std::cerr << "Журнал сборки: " << buffer << std::endl;
    	return 0;
	}

    // Создание ядра и установка аргументов
	cl_kernel kernelS = clCreateKernel(program, "countSum", nullptr);


	size_t range = 256;
	int n = 170;
	cl_double* result = (cl_double*)malloc(sizeof(cl_double) * range);
	cl_int* iterations = (cl_int*)malloc(sizeof(cl_int) * range);
	cl_mem bufferResult = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, sizeof(cl_double) * range, result, nullptr);
	cl_mem iterResult = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, sizeof(cl_int) * range, iterations, nullptr);
    double total_time = 0;
    int total_iterations = 0;
	for (; a <= b + h; a += h) {
		double x = a;
		double y_value = (1 + 2*x*x) * exp(x*x);
		clSetKernelArg(kernelS, 0, sizeof(cl_mem), (void*)&bufferResult);
		clSetKernelArg(kernelS, 1, sizeof(cl_mem), (void*)&iterResult);
		clSetKernelArg(kernelS, 2, sizeof(double), (void*)&x);
		clSetKernelArg(kernelS, 3, sizeof(double), (void*)&tolerance);
		clSetKernelArg(kernelS, 4, sizeof(double), (void*)&y_value);
		clSetKernelArg(kernelS, 5, sizeof(int), (void*)&n);

        // Выполнение ядра и измерение времени
		auto start = std::chrono::high_resolution_clock::now();
        clEnqueueNDRangeKernel(queue, kernelS, 1, nullptr, &range, 0, 0, nullptr, nullptr);
	    clFinish(queue);
		auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_microsecs = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		total_time += elapsed_microsecs.count();
		total_iterations += iterations[0];
        // Запись результатов в файл
		logfile << "Value: " << a << "\n";
		logfile << "Y(" << a <<") = " << std::setprecision(12) << y_value << "\n";
		logfile << "S(" << a <<") = " << std::setprecision(12) << result[0] << "\n";
		logfile << "Iterations: " << iterations[0] << "\n";
		logfile << "Time for iteration: " << elapsed_microsecs.count() << "\n";
		logfile << "Time elapsed: " << total_time << "\n";
		logfile << "Total iterations: " << total_iterations << "\n";
		logfile << "======================================\n";
    }
    logfile.close();
	clReleaseMemObject(bufferResult);
	clReleaseMemObject(iterResult);
	clReleaseKernel(kernelS);
	clReleaseProgram(program);
	clReleaseCommandQueue(queue);
	clReleaseContext(context);
	std::cout << "Time elapsed " << total_time << "\n";
    return 0;
}