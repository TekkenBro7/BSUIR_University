#pragma once

extern "C" __declspec(dllexport) long long proverka();
extern "C" __declspec(dllexport) long long proverka1();
extern "C" __declspec(dllexport) void privetstvie();
extern "C" __declspec(dllexport) long double* massive(long double* arr, long long N);
extern "C" __declspec(dllexport) void iznachalniy(long double* arr, long long N);
extern "C" __declspec(dllexport) long double summa(long long i, long double* arr, long long num);
extern "C" __declspec(dllexport) void other(long double* arr, long long N);
extern "C" __declspec(dllexport) void destroyer(long double* arr);