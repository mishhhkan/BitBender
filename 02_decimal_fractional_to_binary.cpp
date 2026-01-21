/*
Программа: Перевод дробного числа из десятичной системы в двоичную
Раздел методического пособия: Раздел 2. Перевод чисел с плавающей точкой из 10СС в 2СС
Описание: Реализует перевод положительного дробного числа из 10-й СС в 2-ю СС с подробным выводом шагов
*/


#include <iostream> // Библиотека для ввода-вывода


using namespace std; // Пространство имен std


int main() {
    // Заголовок и ввод данных
    cout << "=== Программа перевода числа с плавающей точкой из 10 СС в 2 СС ===\n";
    cout << "Введите дробное число от 0 до 255 в 10 СС для перевода (например 10.5): ";
    float number; // Исходное число в 10 СС
    cin >> number; // Ввод исходного числа в 10 СС

    // Разделение на целую и дробную части
    int integer_part = (int) number; // Целая часть числа
    float fractional_part = number - integer_part; // Дробная часть числа

    cout << "Перевод числа " << number << " из 10 СС в 2 СС:\n";
    cout << "Целая часть: " << integer_part << "\n";
    cout << "Дробная часть: " << fractional_part << "\n";

    // Проверка на нулевое число (0 в 10 СС = 0 в 2 СС)
    if (number == 0.0) {
        cout << "Результат перевода: 0\n";
        return 0;
    }

    // Перевод целой части
    string integer_bin; // Бинарное представление целой части
    int step = 1; // Счетчик шагов для целой части

    if (integer_part == 0) {
        integer_bin = "0";
    } else {
        int num = integer_part;
        while (num > 0) {
            int ost = num % 2; // Вычисление остатка от деления на 2
            integer_bin = to_string(ost) + integer_bin; // Добавление остатка в начало строки
            cout << "Шаг " << step << " (целая часть): число = " << num
                    << ", остаток = " << ost << '\n';
            num = num / 2; // Целочисленное деление на 2
            step = step + 1; // Увеличение счетчика шагов
        }
    }

    // Перевод дробной части
    string fractional_bin; // Строка для хранения двоичного представления дробной части
    int step_frac = 1; // Счетчик шагов для дробной части

    if (fractional_part > 0.0) {
        cout << "\nПеревод дробной части:\n";
        while (fractional_part > 0.0) {
            cout << "Шаг " << step_frac << " (дробная часть): дробь = " << fractional_part
                    << ", умножить на 2 = " << fractional_part * 2.0 << '\n';
            fractional_part = fractional_part * 2.0; // Умножение дробной части на 2
            int bit = (int) fractional_part; // Извлечение целой части результата умножения
            cout << "Целая часть (бит) = " << bit << '\n';
            fractional_bin = fractional_bin + to_string(bit); // Добавление бита в конец строки
            fractional_part = fractional_part - bit; // Обновление дробной части
            step_frac = step_frac + 1; // Увеличение счетчика шагов
        }
    }

    // Сборка результата
    string result = integer_bin + "." + fractional_bin;

    cout << "Результат перевода: " << result << '\n';
    return 0;
}
