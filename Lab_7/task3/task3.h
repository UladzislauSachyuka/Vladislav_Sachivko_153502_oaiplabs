#pragma once
#include <iostream>

using namespace std;

int getinput();
void binary(char* ar, int num, int& len);
void dop_code(char* ar, int len);
void from_dop_to_direct_code(char* ar, int len);
void addition(char* ar1, char* ar2, char* add, int len, int num1, int num2);