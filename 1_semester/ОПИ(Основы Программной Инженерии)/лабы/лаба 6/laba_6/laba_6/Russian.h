#include<iostream>
#include<string>
using namespace std;
void russian() {
    string input;
    cout << "<------------------------------------------------------------------->" << endl;
    cout << "������� �������� ������ �������� �������� ��������: ";
    getline(cin, input);
    for (int i = 0; i < input.length(); i++)
    {
        unsigned char q = input[i];
        int q_code = static_cast<int>(q);
        if (q_code >= 192 && q_code <= 255) {
            int toupperLet_1 = 0, tolowerLet_1 = 0;

            if (q_code > 223) {
                toupperLet_1 = q_code - 32;
                tolowerLet_1 = q_code;
            }
            else if (q_code > 191 && q_code < 224) {
                toupperLet_1 = q_code;
                tolowerLet_1 = q_code + 32;
            }

            int difference_1 = abs(toupperLet_1 - tolowerLet_1);
            cout << "��� ��������� ����� '" << (char)toupperLet_1 << "' (ASCII: " << toupperLet_1 << ") � ��� �������� ����� '"
                << (char)tolowerLet_1 << "' (ASCII: " << tolowerLet_1 << ")." << endl;
            cout << "������� ����� ������: " << difference_1 << endl;
        }
        else {
            cout << "������ '" << q << "' �� �������� ������ �������� ��������." << endl;
        }
    }
}