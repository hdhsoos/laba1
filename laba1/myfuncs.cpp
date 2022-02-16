#include <iostream>
#include <fstream>

using namespace std;

int isdi(char s[]) {
    int i{};
    for (i = 0; i < 256; i++) {
        if (!isdigit(s[i])) {
            return 1;
        }
    }
    return 0;
}

int fail() {
    cout << "Хорошо, читаю файл." << endl;
    ifstream fin("1laba.txt");
    if (!fin.is_open())
        cout << "Файл невозможно открыть. Завершаю работу." << endl;
    else {
        char a1[256]{}, a2[256]{}; // Если будем использовать double,
                                   // число будет сильно округляться. 
        int i{};
        fin >> a1;
        bool isd;
        isd = isdi(a1);
        if (isd == 1) {
            cout << "Ошибка ввода. Завершаю работу." << endl;
            return 0;
        }
        ofstream fout("1labaout.txt");
        for (i = 0; i < 69; i++) {
            fin >> a2;
            isd = isdi(a2);
            if (isd == 1) {
                cout << "Ошибка ввода. Завершаю работу." << endl;
                return 0;
            }
            fout << a2;
            fout << " ";
            cout << a2;
            cout << " ";
        }
        fout << a1;
        cout << a1;
        fin.close();
        fout.close();
        return 0;
    }
}

void cons() {
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
        fout << s2;
        fout << " ";
        cout << s2;
        cout << " ";
    }
    cout << s1 << endl;
    fout << s1 << endl;
    fout.close();
    cout << "Хотите повторить ввод исходных данных ? Да — 1, Нет — 0." << endl;
    int a{};
    cin >> a;
    if (a == 1) {
        cons();
    }
    else {
        cout << "Хорошо, завершаю работу." << endl;
    }
}
