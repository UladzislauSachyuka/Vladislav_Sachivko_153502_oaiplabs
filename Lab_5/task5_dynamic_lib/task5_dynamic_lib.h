#pragma once
extern "C" int _declspec(dllexport) _stdcall getinput();
extern "C" int _declspec(dllexport) _stdcall getelem();
extern "C" void _declspec(dllexport) _stdcall array_output(int n, int k, int** arr);
extern "C" double _declspec(dllexport) _stdcall average(int count, int* arr1);