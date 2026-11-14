//Цель перегрузки состоит в том, чтобы функция с одним именем по разному выполнялась и
// возвращала разные значения при обращении к ней с различными типами и различным числом
// фактических параметров.Для обеспечения перегрузки функций необходимо для каждого имени
// функции определить сколько различных функций с ним связано.
//а) для вычитания вещественных чисел;
//б) для вычитания комплексных чисел.

#include <iostream>
using namespace std;

// Структура комплексного числа
struct Complex
{
    double real; // Действительная часть
    double imag; // Мнимая часть
};

// Функция для вычитания вещественных чисел
double minus(double a, double b)
{
    return a - b;
}

// Функция для вычитания комплексных чисел
Complex minus(Complex a, Complex b)
{
    Complex result;

    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;

    return result;
}

int main()
{
    // а) Вычитание вещественных чисел
    double x = 10.5;
    double y = 4.2;

    double result1 = minus(x, y);

    cout << "Subtraction of real numbers: ";
    cout << result1 << endl;

    // б) Вычитание комплексных чисел
    Complex z1 = { 8, 5 }; // Первое число: 8 + 5i
    Complex z2 = { 3, 2 }; // Второе число: 3 + 2i

    Complex result2 = minus(z1, z2);

    cout << "Subtraction of complex numbers: ";
    cout << result2.real;

    if (result2.imag >= 0)
        cout << " + " << result2.imag << "i";
    else
        cout << " - " << -result2.imag << "i";

    cout << endl;

    return 0;
}
