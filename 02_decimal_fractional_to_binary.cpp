/*
Программа: Перевод числа с плавающей точкой из десятичной в двоичную
Раздел методички: Раздел 2. Перевод чисел с плавающей точкой из 10СС в 2СС
Описание: Отдельно переводит целую и дробную части в двоичное представление
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string int_to_bin(long long n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

string frac_to_bin(double f, int max_prec = 20) {
    string res = "";
    while (f > 0 && res.length() < max_prec) {
        f *= 2;
        int bit = (f >= 1.0 ? 1 : 0);
        res += ('0' + bit);
        if (bit) f -= 1.0;
    }
    return res;
}

int main() {
    double num;
    cout << "Введите положительное число с плавающей точкой в 10 СС: ";
    cin >> num;

    if (num < 0) num = -num; // знак игнорируем для примера

    long long int_part = (long long) num;
    double frac_part = num - int_part;

    string bin_int = int_to_bin(int_part);
    string bin_frac = frac_to_bin(frac_part);

    cout << "В 2 СС: " << (bin_int == "0" ? "0" : bin_int) << "." << bin_frac << endl;

    return 0;
}
