#include<iostream>
#include<string>
using namespace std;
void number()
{
    string input;
    cout << "<------------------------------------------------------------------->" << endl;
    cout << "������� ����� ��� ������ ����: ";
    getline(cin, input);
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (static_cast<int>(c) >= 48 && static_cast<int>(c) <= 57) {
            cout << "��� ����� " << c << " = " << static_cast<int>(c) << endl;
        }
        else {
            cout << "������ '" << c << "' �� �������� ������." << endl;
        }
    }
}