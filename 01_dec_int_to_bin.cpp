/*
Программа: Перевод целого числа из десятичной системы в двоичную
Раздел методички: Раздел 1. Перевод целых чисел из 10СС в 2СС
Описание: Реализует перевод положительного целого числа из 10-й СС в 2-ю СС с дополнением нулями до заданной разрядности
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long num;
    int bits = 8; // можно изменить

    cout << "Введите целое положительное число в 10 СС: ";
    cin >> num;

    if (num == 0) {
        cout << "В 2 СС: 0" << endl;
        return 0;
    }

    string bin = "";
    long long temp = num;
    while (temp > 0) {
        bin += (temp % 2 == 0 ? '0' : '1');
        temp /= 2;
    }
    reverse(bin.begin(), bin.end());

    cout << "В 2 СС: " << bin << endl;

    return 0;
}
