#include<iostream>
#include<cmath>
#include<Windows.h>
#include<string>
#include "Latina.h"
#include "Russian.h"
#include "number.h"
#include "variant.h"
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int variant;
    variantt();
    cin >> variant;
    cin.ignore(); // �� ������� ����� ����� �������������� getline, � �� ����� ���� ������
    switch (variant) {
    case 1: {
        latina();
        break;
    }

    case 2: {
        russian();
        break;
    }

    case 3: {
        number();
        break;
    }

    case 4: {
        cout << "<------------------------------------------------------------------->" << endl;
        cout << "������� �� ���������";
        break;
    }
    default:
    {
        cout << "�� �� ������ �����" << endl;
        break;
    }
    }
    return 0;
}
