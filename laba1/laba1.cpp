#include <iostream>
#include <fstream>

using namespace std;
int fail() {
    cout << "Хорошо, читаю файл." << endl;
    ifstream fin("1laba.txt");
    if (!fin.is_open())
        cout << "Файл невозможно открыть. Завершаю работу." << endl;
    else {
        char a1[15]; // Предположим, что пользователь не будет вводить числа,
        char a2[15]; // длина которых больше 15 символов.
        int i;
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
    return 0;
}

int cons() {
    cout << "Хорошо, вводите данные. Все числа должны быть в одной строке." << endl;
    char s1[15], s2[15]; // Снова надеемся, что числа будут короче 15 символов.
    cin >> s1;
    int i;
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
    int a;
    cin >> a;
    if (a == 1) {
        cons();
    }
    else {
        cout << "Хорошо, завершаю работу." << endl;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите ввести данные из файла или из консоли?" << endl;
    cout << "0 - из файла, 1 - из консоли." << endl;
    int a;
    cin >> a;
    if (a == 1) {
        cons();
    }
    else {
        fail();
    }
}
