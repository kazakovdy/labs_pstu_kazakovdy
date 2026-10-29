#include <iostream>
using namespace std;
int main() {
    // Установление отображения русского языка в консоли
    setlocale(LC_ALL, ".UTF8");
    double m, n;
    cout << "Введите два числа: ";
    cin >> m >> n;
    // сохраняем исходные значения
    double m0 = m, n0 = n;
    // объявление переменных для результатов
    double res1, res2, res3;
    //результат
    res1 = m - ++n;        // 1) m-++n  =>  m - (++n)
    n = n0; m = m0;        // возвращаем исходные значения
    res2 = ++m > --n;      // 2) ++m>--n
    n = n0; m = m0;
    res3 = --n < ++m;      // 3) --n<++m
   
    cout << "Результат m-++n = " << res1 << endl; // Вывод
    cout << "Результат ++m>--n = " << res2 << endl; //Вывод
    cout << "Результат --n<++m = " << res3 << endl; //Вывод
    return 0;
}