#include <iostream>
#include <fstream>

using namespace std;

int isdi(char s[]) {
    int i{}; // функция, в которой мы проверяет является ли какой-то из символов не числом
    for (i = 0; i < 256; i++) {
        if (s[i] == '.' or s[i] == '\0') {
            continue;
        }
        if (!isdigit(s[i])) {
            return 1;
        }
    }
    return 0;
}

int vivod() {
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите вывести данные в файл или консоль?" << endl;
    cout << "0 - в файл, 1 - в консоль." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        return 1;
    }
    else {
        if (a[0] == '0') {
            return 0;
        }
        else {
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            vivod();
        }
    }
}

int fail() {
    // если пользователь выбирает ввод из файла, запускается эта фнкц
    int x;
    x = vivod();
    cout << "Хорошо, читаю файл." << endl;
    ifstream fin("1laba.txt");
    if (!fin.is_open())
        cout << "Файл невозможно открыть. Завершаю работу." << endl;
    else {
        char a1[256]{}, a2[256]{};
        int i{};
        fin >> a1;
        // принимаем a1
        bool isd;
        isd = isdi(a1); // проверка
        if (isd == 1) {
            cout << "Ошибка ввода. Вы ввели не число. Завершаю работу." << endl;
            return 0;
        }
        ofstream fout("1labaout.txt"); 
        for (i = 0; i < 69; i++) {
            // принимаем и сразу выводим a2...an
            fin >> a2;
            isd = isdi(a2); // проверка
            if (isd == 1) {
                cout << "Ошибка ввода. Вы ввели не число. Завершаю работу." << endl;
                return 0;
            }
            if (x == 0) {
                fout << a2;
                fout << " ";
            }
            else {
                cout << a2;
                cout << " ";
            }
        }
        // выводим a1
        if (x == 0) {
            fout << a1;
            fout.close();
        }
        else {
            cout << a1;
        }
        fin.close();
        return 0;
    }
}

void cons() {
    // если пользователь выбирает ввод с консоли, запускается эта фнкц
    int x;
    x = vivod();
    cout << "Хорошо, вводите данные. Все числа должны быть в одной строке через пробел." << endl;
    char s1[256]{}, s2[256]{};
    cin >> s1;
    int i{};
    bool isd{};
    isd = isdi(s1);
    if (isd == 1) {
        cout << "Ошибка ввода. Попробуйте снова." << endl;
        cons();
    }
    ofstream fout("1labaout.txt");
    for (i = 0; i < 69; i++) {
        cin >> s2;
        isd = isdi(s1);
        while (isd == 1) {
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            cin >> s2;
            isd = isdi(s1);
        }
        if (x == 0) {
            fout << s2;
            fout << " ";
        }
        else {
            cout << s2;
            cout << " ";
        }
    }
    if (x == 1) {
        cout << s1 << endl;
    }
    else {
        fout << s1 << endl;
        fout.close();
    }
    dend();
}

int dend() {
    cout << "Хотите повторить ввод исходных данных ? Да — 1, Нет — 0." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        cons();
    }
    else {
        if (a[0] == '0') {
            cout << "Хорошо, завершаю работу" << endl;
            return 0;
        }
        else {
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            dend();
        }
    }
}
