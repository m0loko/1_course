#include <stdio.h>
#include <Windows.h>
#include<iostream>
#include<string>
using namespace std;
//������� ��� �������� �� �������� � ������������
string binaryToOctal(string binary) {
    // ��� � ���������� �������� ����� � �����, ������� 3, ������� ���� �����
    int length = binary.length();
    int remainder = length % 3;
    if (remainder != 0) {
        int padding = 3 - remainder; // ��� � ������ ������� ����� ����� ��������
        for (int i = 0; i < padding; i++) {
            binary = '0' + binary;
        }
    }
    string octal;
    for (int i = 0; i < binary.length(); i += 3) {
        string binaryGroup = binary.substr(i, 3); // ����� substr ���� 3 ������� ������� � i �������� ������
        char octalDigit;
        // ��� � ������� ������� �������������� ����� �������� ���� � ������������ �����
        if (binaryGroup == "000") octalDigit = '0';
        else if (binaryGroup == "001") octalDigit = '1';
        else if (binaryGroup == "010") octalDigit = '2';
        else if (binaryGroup == "011") octalDigit = '3';
        else if (binaryGroup == "100") octalDigit = '4';
        else if (binaryGroup == "101") octalDigit = '5';
        else if (binaryGroup == "110") octalDigit = '6';
        else if (binaryGroup == "111") octalDigit = '7';
        else octalDigit = '0';
        octal += octalDigit;
    }

    return octal;
}
//������� ��� �������� �� �������� � ����������
int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1; // ��� ��������� ������� ������: 2^0 = 1
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}
//������� ��� �������� �� �������� � �����������������
string binaryToHex(string binary) {
    // ��� � ���������� �������� ����� � �����, ������� 3, ������� ���� �����
    int length = binary.length();
    int remainder = length % 4;
    if (remainder != 0) {
        int padding = 4 - remainder; // ��� � ������ ������� ����� ����� ��������
        for (int i = 0; i < padding; i++) {
            binary = '0' + binary;
        }
    }
    string hexadecimal;
    // �������� �� �������� ������ �������� �� 4 �����
    for (int i = 0; i < binary.length(); i += 4) {
        string binaryGroup = binary.substr(i, 4); // ����� substr ���� 4 ������� ������� � i �������� ������
        char hexDigit;

        // ������� �������������� ������ �������� ���� � ����������������� �����
        if (binaryGroup == "0000") hexDigit = '0';
        else if (binaryGroup == "0001") hexDigit = '1';
        else if (binaryGroup == "0010") hexDigit = '2';
        else if (binaryGroup == "0011") hexDigit = '3';
        else if (binaryGroup == "0100") hexDigit = '4';
        else if (binaryGroup == "0101") hexDigit = '5';
        else if (binaryGroup == "0110") hexDigit = '6';
        else if (binaryGroup == "0111") hexDigit = '7';
        else if (binaryGroup == "1000") hexDigit = '8';
        else if (binaryGroup == "1001") hexDigit = '9';
        else if (binaryGroup == "1010") hexDigit = 'A';
        else if (binaryGroup == "1011") hexDigit = 'B';
        else if (binaryGroup == "1100") hexDigit = 'C';
        else if (binaryGroup == "1101") hexDigit = 'D';
        else if (binaryGroup == "1110") hexDigit = 'E';
        else if (binaryGroup == "1111") hexDigit = 'F';
        else hexDigit = '0';
        hexadecimal += hexDigit;
    }
    return hexadecimal;
}

//������� ��� �������� �� ������������ � ��������
string octalToBinary(string octal) {
    string binary;
    for (int i = 0; i < octal.length(); i++) {
        int digit = octal[i] - '0'; //����������� ������ ������� i � ������������ ������� � ��� ������������� ������������� , ������� ��� ������� � ������� ��������� windows-1251 
        if (digit < 0 || digit > 7) {
            cout << "������������ ������������ �����: " << octal[i] << endl;
            return "";
        }

        // ������� ������ ���� �� ����������� �� � ������������
        if (digit == 0) binary += "000";
        else if (digit == 1) binary += "001";
        else if (digit == 2) binary += "010";
        else if (digit == 3) binary += "011";
        else if (digit == 4) binary += "100";
        else if (digit == 5) binary += "101";
        else if (digit == 6) binary += "110";
        else if (digit == 7) binary += "111";
    }
    if (binary.empty()) return "0";// ���� ������ ����� ������, �� ���������� ������ "0"

    return binary;
}
//������� ��� �������� �� ������������ � ����������
int octalToDecimal(string octal) {
    string binary = octalToBinary(octal);
    int bindec = binaryToDecimal(binary);
    return bindec;
}
//������� ��� �������� �� ������������ � �����������������
string octalTohex(string octal)
{
    string binary = octalToBinary(octal);
    string binhex = binaryToHex(binary);
    return binhex;
}

//������� ��� �������� �� ���������� � ��������
string decimalToBinary(string decimalStr) {
    int decimal = stoi(decimalStr); // stoi ����������� ������ � ����� �����
    if (decimal == 0) return "0";
    string binary;
    while (decimal > 0) {
        int remainder = decimal % 2; // ������� �� ������� �� 2
        binary += to_string(remainder); // ��� �� ����������� remainder �� ���� int � string � ��������� ������� � ������
        decimal /= 2;
    }

    reverse(binary.begin(), binary.end());  //reverse �������������� ������, ����� �������� ���������� ������� � ������
    return binary;
}
//������� ��� �������� �� ���������� � ������������
string decimalToOctal(string decimalStr)
{
    string binary = decimalToBinary(decimalStr);
    string binoct = binaryToOctal(binary);
    return binoct;
}
//������� ��� �������� �� ���������� � �����������������
string decimaltoHex(string decimalStr)
{
    string binary = decimalToBinary(decimalStr);
    string binhex = binaryToHex(binary);
    return binhex;
}

//������� ��� �������� �� ����������������� � ��������
string hexToBinary(string hex) {
    string binary;
    for (int i = 0; i < hex.length(); i++) {
        char c = hex[i];
        if (c >= 'a' && c <= 'f') {
            c -= 32; // ��� �� ���������� �������� ����� � ��������� (�� ����� , ��� � ��������� windows-1251 �������� ����� ������ ��������� �� 32(� 10�.�.)
        }
        if (c == '0') binary += "0000";
        else if (c == '1') binary += "0001";
        else if (c == '2') binary += "0010";
        else if (c == '3') binary += "0011";
        else if (c == '4') binary += "0100";
        else if (c == '5') binary += "0101";
        else if (c == '6') binary += "0110";
        else if (c == '7') binary += "0111";
        else if (c == '8') binary += "1000";
        else if (c == '9') binary += "1001";
        else if (c == 'A') binary += "1010";
        else if (c == 'B') binary += "1011";
        else if (c == 'C') binary += "1100";
        else if (c == 'D') binary += "1101";
        else if (c == 'E') binary += "1110";
        else if (c == 'F') binary += "1111";
        else {
            cout << "������������ ����������������� �����: " << c << endl;
            return "";
        }
    }
    if (binary.empty()) { //empty ��������� ������ �� ������ ������
        return "0";
    }
    else {
        return binary;
    }
}
//������ ��� �������� �� ����������������� � ������������
string hexToOctal(string hex) {
    string binary = hexToBinary(hex);
    string binoct = binaryToOctal(binary);
    return binoct;
}
//������ ��� �������� �� ����������������� � ����������
int hexToDec(string hex) {
    string binary = hexToBinary(hex);
    int bindec = binaryToDecimal(binary);

    return bindec;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int inputnum, reinputnum;
    string number;

    cout << "�������� ������� ��������� ��� ����� �����:\n";
    cout << "1. �������� (������� 2)\n";
    cout << "2. ������������ (������� 8)\n";
    cout << "3. ���������� (������� 10)\n";
    cout << "4. ����������������� (������� 16)\n";
    cout << "����: ";
    cin >> inputnum;

    switch (inputnum) {
    case 2: {
        cout << "������� ����� � �������� �������: ";
        cin >> number;
        cout << "�������� ������� ��������� ��� �������� �����:\n";
        cout << "1. ������������ (������� 8)\n";
        cout << "2. ���������� (������� 10)\n";
        cout << "3. ����������������� (������� 16)\n";
        cout << "����: ";
        cin >> reinputnum;

        switch (reinputnum) {
        case 8: {
            string octal = binaryToOctal(number);
            cout << "������������ �����: " << octal << endl;
            break;
        }
        case 10:
        {
            int decimal = binaryToDecimal(number);
            cout << "���������� �����: " << decimal << endl;
            break;
        }
        case 16:
        {
            string hexadecimal = binaryToHex(number);
            cout << "����������������� �����: " << hexadecimal << endl;
            break;
        }
        default:
            cout << "������ �������� ���\n";
            return 1;
        }
        break;
    }

    case 8: {
        cout << "������� ����� � ������������ �������: ";
        cin >> number;
        cout << "�������� ������� ��������� ��� �������� �����:\n";
        cout << "1. �������� (������� 2)\n";
        cout << "2. ���������� (������� 10)\n";
        cout << "3. ����������������� (������� 16)\n";
        cout << "����: ";
        cin >> reinputnum;
        switch (reinputnum)
        {
        case 2:
        {
            string binary = octalToBinary(number);
            cout << "������������ �����: " << binary << endl;
            break;
        }
        case 10: {
            int binary = octalToDecimal(number);
            cout << "���������� �����: " << binary << endl;
            break;
        }
        case 16: {
            string binary = octalTohex(number);
            cout << "���������� �����: " << binary << endl;
            break;
        }
        default:
        {
            cout << "������ �������� ���\n";
            return 1;
            break;
        }
        }
        break;
    }
    case 10: {
        cout << "������� ����� � ���������� �������: ";
        cin >> number;
        cout << "�������� ������� ��������� ��� �������� �����:\n";
        cout << "1. �������� (������� 2)\n";
        cout << "2. ������������ (������� 8)\n";
        cout << "3. ����������������� (������� 16)\n";
        cout << "����: ";
        cin >> reinputnum;
        switch (reinputnum)
        {
        case 2: {
            string binary = decimalToBinary(number);
            cout << "�������� �������������: " << binary << endl;
            break;
        }
        case 8:
        {
            string octal = decimalToOctal(number);
            cout << "������������ �������������: " << octal << endl;
            break;
        }
        case 16:
        {
            string hex = decimaltoHex(number);
            cout << "����������������� �������������: " << hex << endl;
        }
        default:
        {
            cout << "������ �������� ���\n";
            return 1;
            break;
        }
        }
        break;
    }
    case 16: {
        cout << "������� ����� � ����������������� �������: ";
        cin >> number;
        cout << "�������� ������� ��������� ��� �������� �����:\n";
        cout << "1. �������� (������� 2)\n";
        cout << "2. ������������ (������� 8)\n";
        cout << "3. ���������� (������� 10)\n";
        cout << "����: ";
        cin >> reinputnum;
        switch (reinputnum)
        {
        case 2:
        {
            string binary = hexToBinary(number);
            cout << "�������� �����: " << binary << endl;
            break;
        }
        case 8:
        {
            string binary = hexToOctal(number);
            cout << "������������ �����: " << binary << endl;
            break;
        }
        case 10:
        {
            int binary = hexToDec(number);
            cout << "���������� �����: " << binary << endl;
            break;
        }
        default:
        {
            cout << "�������� ����� ������� ���������.\n";
            return 1;
        }
        }
    }
    }

    return 0;
}
