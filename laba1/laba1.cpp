﻿#include <iostream>
using namespace std;
#include "C:\Users\andre\source\repos\laba1\laba1\myfuncs.h"
#include "C:\Users\andre\source\repos\laba1\laba1\myfuncs.cpp"

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите ввести данные из файла или из консоли?" << endl;
    cout << "0 - из файла, 1 - из консоли." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        cons();
    }
    else {
        if (a[0] == '0') {
            fail();
        }
        else {
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            main();
        }
    }
}

