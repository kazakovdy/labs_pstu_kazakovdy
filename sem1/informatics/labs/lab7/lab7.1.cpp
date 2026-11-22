#include <iostream>
using namespace std;

// Комплексное число: re + im * i
struct Complex {
    double re;
    double im;
};

// а) вычитание вещественных чисел
double subtract(double a, double b) {
    return a - b;
}

// б) вычитание комплексных чисел
Complex subtract(const Complex& a, const Complex& b) {
    Complex result;
    result.re = a.re - b.re;
    result.im = a.im - b.im;
    return result;
}

// Вывод комплексного числа в виде a + bi / a - bi
void print(const Complex& z) {
    cout << z.re << (z.im < 0 ? " - " : " + ")
         << (z.im < 0 ? -z.im : z.im) << "i";
}

int main() {
    // а) вещественные числа
    double x, y;
    cout << "Введите два вещественных числа: ";
    cin >> x >> y;
    cout << x << " - " << y << " = " << subtract(x, y) << "\n\n";

    // б) комплексные числа
    Complex z1, z2;
    cout << "Введите первое комплексное число (re im): ";
    cin >> z1.re >> z1.im;
    cout << "Введите второе комплексное число (re im): ";
    cin >> z2.re >> z2.im;

    Complex diff = subtract(z1, z2);

    cout << "(";  print(z1);   cout << ") - (";
    print(z2);    cout << ") = ";
    print(diff);  cout << "\n";

    return 0;
}