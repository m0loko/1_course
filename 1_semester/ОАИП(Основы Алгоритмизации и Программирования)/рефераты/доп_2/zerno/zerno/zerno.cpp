#include<iostream>
#include<Windows.h>
using namespace std;
#define USA_WHEAT 1110000000000000ULL //ull ����������, ��� ��� ������ unsigned long long
#define RUSSIA_WHEAT 2088000000000000ULL 
#define BELARUS_WHEAT 54000000000000ULL

void wheat(string country, unsigned long long int wheat) {
    unsigned long long int sn = 1;
    for (int i = 1; i < 65; i++) {
        sn = sn << 1; // ����� ����� �� 1 ���, ������������ ��������� �� 2. ������ � ���, ��� �� ��������� �� ������ �.�. ��� �������� ���������� �� ������ ����������
        if (sn > wheat) {
            cout << "�� " << i << " ������ ���������� ���� ���������� ������ ������� " << country << endl;
            break;
        }
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    wheat("���������� ������", USA_WHEAT);
    wheat("������", RUSSIA_WHEAT);
    wheat("��������", BELARUS_WHEAT);
    return 0;
}
