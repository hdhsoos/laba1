#include <iostream>
#include <fstream>

using namespace std;
void fail() {
    cout << "Хорошо, читаю файл." << endl;
    ifstream fin("1laba.txt");
    if (!fin.is_open())
        cout << "Файл невозможно открыть. Завершаю работу." << endl;
    else {
        char a1[15]{}, a2[15]{}; // Если будем использовать double,
                             // число будет сильно округляться. 
                             // Поэтому удобнее сохранить хотя бы первые 15 знаков.
        int i{};
        fin >> a1;
        ofstream fout("1labaout.txt");
        for (i = 0; i < 69; i++) {
            fin >> a2;
            fout << a2;
            fout << " ";
            cout << a2;
            cout << " ";
        }
        fout << a1;
        cout << a1;
        fin.close();
        fout.close();
    }
}

void cons() {
    cout << "Хорошо, вводите данные. Все числа должны быть в одной строке." << endl;
    char s1[15]{}, s2[15]{};
    cin >> s1;
    int i{};
    ofstream fout("1labaout.txt");
    for (i = 0; i < 69; i++) {
        cin >> s2;
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

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите ввести данные из файла или из консоли?" << endl;
    cout << "0 - из файла, 1 - из консоли." << endl;
    int a{};
    cin >> a;
    if (a == 1) {
        cons();
    }
    else {
        fail();
    }
}

