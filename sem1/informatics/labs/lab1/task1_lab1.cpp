#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
int main() {
	setlocale(LC_ALL, ".UTF8"); // вывод кириллицы
	cout.precision(15); //длина вывода
	// для float
	float a, b;
	cout << "Введите a, b: " << endl;
	cin >> a >> b;
	cout << "Вычисление для float: " << endl;
	float c1 = pow(a - b, 3);
	float c2 = pow(a, 3) - 3 * pow(a, 2) * b;
	float c3 = pow(b, 3) - 3 * a * pow(b, 2);  // расчет знаменателя
	cout << "Знаменатель: " << c3 << endl; 
	float c4 = c1 - c2; // расчет числителя
	cout << "Числитель: " << c4 << endl; 
	float c5 = c4 / c3; // расчет ответа
	cout << "Результат: " << c5 << endl;

	//для double
	cout << "Вычисление для double: " << endl;
	double A, B;
	A = a;
	B = b;
	double C1 = pow(A - B, 3);
	double C2 = pow(A, 3) - 3 * pow(A, 2) * B;
	double C3 = pow(B, 3) - 3 * A * pow(B, 2);// расчет знаменателя
	cout << "Знаменатель: " << C3 << endl; 
	double C4 = C1 - C2; // Расчет числителя
	cout << "Числитель: " << C4 << endl;
	double C5 = C4 / C3;// Расчет ответа
	cout << "Результат: " << C5 << endl;
	return 0;
}