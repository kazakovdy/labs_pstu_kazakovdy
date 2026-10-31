#include <iostream>   // ввод/вывод (cout)
#include <cmath>      // exp, cos, sin, fabs, acos
#include <iomanip>    // setprecision
using namespace std;

int main()
{
    // Число pi: acos(-1) = pi
    const double PI = acos(-1.0);

    const double a = 0.1;      // левая граница диапазона x
    const double b = 1.0;      // правая граница диапазона x
    const int    k = 10;       // число шагов по x
    const int    N = 25;       // заданное число слагаемых
    const double eps = 0.0001; // заданная точность
    double h = (b - a) / k;    // шаг изменения x

    cout << "Вычисление функции" << endl;

    // Внешний цикл: x меняется от a до b с шагом h
    for (int i = 0; i <= k; i++)
    {
        double x = a + i * h;  // текущее значение x

        // а) сумма для заданного n (арифметический цикл)
        // c = x^n / n!, начальное значение c_0 = 1
        double c  = 1.0;
        double SN = 1.0;       // первое слагаемое равно 1
        for (int n = 1; n <= N; n++)
        {
            c = c * x / n;     // c_n = c_(n-1) * x / n
            // добавляем a_n = c_n * cos(n*pi/4)
            SN += c * cos(n * PI / 4);
        }

        // б) сумма для заданной точности (итерационный цикл)
        c = 1.0;               // снова c_0 = 1
        double SE = 1.0;
        int n = 0;             // номер слагаемого
        do
        {
            n++;
            c = c * x / n;     // c_n = c_(n-1) * x / n
            SE += c * cos(n * PI / 4);
        } while (fabs(c) >= eps); // пока c_n не меньше eps

        // точное значение функции
        double Y = exp(x * cos(PI / 4)) * cos(x * sin(PI / 4));

        // вывод: X, SN, SE, Y
        cout << fixed << setprecision(5)
             << "X=" << x
             << "\tSN=" << SN
             << "\tSE=" << SE
             << "\tY=" << Y << endl;
    }

    return 0;
}
