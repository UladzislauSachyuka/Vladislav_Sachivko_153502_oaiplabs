#pragma once
extern "C" int _declspec(dllexport) getinput();
extern "C" int _declspec(dllexport) getelem();
extern "C" void _declspec(dllexport) array_output(int n, int k, int** arr);
extern "C" double _declspec(dllexport) average(int count, int* arr1);