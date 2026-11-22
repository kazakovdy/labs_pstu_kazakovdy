// 6. Функция min с переменным числом параметров (int).
// main вызывает min три раза с 5, 10 и 12 параметрами.

#include <iostream>
#include <cstdarg>
using namespace std;

int min(int count, ...)
{
    va_list args;                    // 1. объявляем «указатель» на список
    va_start(args, count);           // 2. ставим его на первый параметр после count
    int mn = va_arg(args, int);      // 3. читаем первое число, args сдвигается
    for (int i = 1; i < count; i++)
    {
        int val = va_arg(args, int); // читаем следующее и снова сдвигаемся
        if (val < mn) mn = val;
    }
    va_end(args);                    // 4. завершаем работу со списком
    return mn;
}
int main()
{
    cout << "Минимальное из 5 чисел: "
         << min(5, 10, 3, 7, 2, 8) << endl;
    cout << "Минимальное из 10 чисел: "
         << min(10, 15, 22, 8, 19, 3, 11, 6, 14, 9, 17) << endl;
    cout << "Минимальное из 12 чисел: "
         << min(12, 25, 17, 30, 12, 5, 18, 21, 9, 14, 7, 20, 16) << endl;
    return 0;
}