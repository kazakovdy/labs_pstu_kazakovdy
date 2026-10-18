#include <iostream>
using namespace std; //пространство
int main()
{
	setlocale(LC_ALL, ".UTF8"); //кириллица
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
	cout << "Сумма ряда с точностью е=10-4 равна: " << sum << endl; //вывод
}