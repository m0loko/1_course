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
    cin.ignore(); // мы очищаем буфер перед использованием getline, а то могут быть ошибки
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
        cout << "Выходим из программы";
        break;
    }
    default:
    {
        cout << "Вы не знаете цифры" << endl;
        break;
    }
    }
    return 0;
}
