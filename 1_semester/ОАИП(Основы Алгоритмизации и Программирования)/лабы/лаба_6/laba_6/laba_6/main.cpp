#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    double p, totalyear = 0;
    cout << "�������, ������� ��� ����� �������� ������������: ";
    cin >> n;
    cout << "�������, �� ������� % ������������ �����������: ";
    cin >> p;
    for (int i = 1; i <= n; i++) {
        double year;
        cout << "������� ��������� �� " << i << " ���: ";
        cin >> year;
        totalyear *= (1 - p / 100);
        totalyear += year;
    }
    cout << "����� ��������� ������������ ������������ �� " << n << " ���: " << totalyear / 2 << " ������." << endl;
    return 0;
}
