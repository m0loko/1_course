#include<iostream>
#include<cmath>
#include<Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int variant;
	cout << "�������� ������� ������������� ���������:" << endl << "1) ����������� ������� �������� ����� � ASCII ����� � ��������� � �������� ���������, ���� ������ ������ ���������� ��������"
		<< endl << "2) ����������� ������� �������� ����� � Windows-1251 ����� � ��������� � �������� ���������, ���� ������ ������ �������� ��������" << endl << "3) ����� � ������� ���� �������, ���������������� ��������� �����"
		<< endl << "4) ����� �� ���������" << "\n\n" << "<------------------------------------------------------------------->" << endl;
	cin >> variant;
	switch (variant)
	{
	case 1: {
		char c;
		cout << "<------------------------------------------------------------------->" << endl;
		cout << "������� ������ ���������� ��������:";
		cin >> c;
		while (static_cast<int>(c) < 65 || (static_cast<int>(c) > 90 && static_cast<int>(c) < 97) || static_cast<int>(c) > 122)
		{
			cout << "������� ������ ���������� �������� ! : ";
			cin >> c;
		}
		int toupperLet = static_cast<int>(toupper(c));
		int tolowerLet = static_cast<int>(tolower(c));
		int difference = abs(toupperLet - tolowerLet);
		cout << "��� ��������� ����� '" << (char)toupper(c) << "' (ASCII: " << toupperLet << ") " << "� ��� �������� ����� '" << (char)tolower(c) << "' (ASCII: " << tolowerLet << ")." << endl;
		cout << "������� ����� ������: " << difference << endl;
		break;
	}

	case 2: {
		unsigned char q;
		cout << "<------------------------------------------------------------------->" << endl;
		cout << "������� ������ �������� �������� ! : ";
		cin >> q;
		while (static_cast<int>(q) < 192 || static_cast<int>(q) > 255) {
			cout << "������� ������ �������� ��������! : ";
			cin >> q;
		}
		int q_code = static_cast<int>(q);
		int toupperLet_1, tolowerLet_1;

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
		break;
	}
	case 3: {
		char c;
		cout << "<------------------------------------------------------------------->" << endl;
		cout << "������� �����" << endl;
		cin >> c;
		while (static_cast<int>(c) < 48 || static_cast<int>(c) > 57)
		{
			cout << "������� ����� ! : ";
			cin >> c;
		}
		cout << "��� ����� " << c << " = " << static_cast<int>(c) << endl;
		break;
	}
	case 4:
	{
		cout << "<------------------------------------------------------------------->" << endl;
		cout << "������� �� ���������";
		break;
	}
	}


	return 0;
}
