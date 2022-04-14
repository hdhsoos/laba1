#include <iostream>
#include <fstream>

using namespace std;

int isdi(char s[]) {
    int i{}; // �������, � ������� �� ��������� �������� �� �����-�� �� �������� �� ������
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
    cout << "�� ������ ������� ������ � ���� ��� �������?" << endl;
    cout << "0 - � ����, 1 - � �������." << endl;
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
            cout << "������ �����. ���������� �����." << endl;
            vivod();
        }
    }
}

int fail() {
    // ���� ������������ �������� ���� �� �����, ����������� ��� ����
    int x;
    x = vivod();
    cout << "������, ����� ����." << endl;
    ifstream fin("1laba.txt");
    if (!fin.is_open())
        cout << "���� ���������� �������. �������� ������." << endl;
    else {
        char a1[256]{}, a2[256]{};
        int i{};
        fin >> a1;
        // ��������� a1
        bool isd;
        isd = isdi(a1); // ��������
        if (isd == 1) {
            cout << "������ �����. �� ����� �� �����. �������� ������." << endl;
            return 0;
        }
        ofstream fout("1labaout.txt"); 
        for (i = 0; i < 69; i++) {
            // ��������� � ����� ������� a2...an
            fin >> a2;
            isd = isdi(a2); // ��������
            if (isd == 1) {
                cout << "������ �����. �� ����� �� �����. �������� ������." << endl;
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
        // ������� a1
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
    // ���� ������������ �������� ���� � �������, ����������� ��� ����
    int x;
    x = vivod();
    cout << "������, ������� ������. ��� ����� ������ ���� � ����� ������ ����� ������." << endl;
    char s1[256]{}, s2[256]{};
    cin >> s1;
    int i{};
    bool isd{};
    isd = isdi(s1);
    if (isd == 1) {
        cout << "������ �����. ���������� �����." << endl;
        cons();
    }
    ofstream fout("1labaout.txt");
    for (i = 0; i < 69; i++) {
        cin >> s2;
        isd = isdi(s1);
        while (isd == 1) {
            cout << "������ �����. ���������� �����." << endl;
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
    cout << "������ ��������� ���� �������� ������ ? �� � 1, ��� � 0." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        cons();
    }
    else {
        if (a[0] == '0') {
            cout << "������, �������� ������" << endl;
            return 0;
        }
        else {
            cout << "������ �����. ���������� �����." << endl;
            dend();
        }
    }
}
