#include<iostream>
#include<string>
using namespace std;
void latina()
{
    string input;
    cout << "<------------------------------------------------------------------->" << endl;
    cout << "������� ������ ��� ������ �������� ���������� ��������: ";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (static_cast<int>(c) >= 65 && (static_cast<int>(c) <= 90 || static_cast<int>(c) >= 97) && static_cast<int>(c) <= 122) {
            int toupperLet = static_cast<int>(toupper(c));
            int tolowerLet = static_cast<int>(tolower(c));
            int difference = abs(toupperLet - tolowerLet);
            cout << "��� ��������� ����� '" << (char)toupper(c) << "' (ASCII: " << toupperLet << ") " << "� ��� �������� ����� '" << (char)tolower(c) << "' (ASCII: " << tolowerLet << ")." << endl;
            cout << "������� ����� ������: " << difference << endl;
        }
        else {
            cout << "������ '" << c << "' �� �������� ��������� ������." << endl;
        }
    }
}