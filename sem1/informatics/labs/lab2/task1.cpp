#include <iostream>
using namespace std; //пространство
#include <clocale>
int main()
{
	setlocale(LC_ALL, "Russian"); //кириллица
	double esp = 1e-4; //точность
	double sum = 0.0;
	double a = 1.0 / 2.0; //первый элемент суммы
	double b = 1.0 / 3.0;//второй элемент суммы
	while (a + b >= esp) //запуск цикла, который прервется при достижении точности
	{
		sum += a + b;
		a /= 2.0;
		b /= 3.0;
	}
	cout << "Summa ryada s tochnostyu e=10^-4 ravna: " << sum << endl; //вывод
}