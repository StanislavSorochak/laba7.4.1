// Lab_7_4_1.cpp
// < Сорочак Станіслав >
// Лабораторна робота № 7.4.1
//Рекурсивний спосіб, Завдання 1
// Варіант 24
#include <iostream>
#include <Windows.h>
#include <iomanip>

void Create(int** a, const int rowCount, const int colCount, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int Sum(int** a, const int rowCount, const int colCount, int i, int j, int sum);

int main(void)
{
	srand((unsigned)time(NULL));

	using std::cout;
	using std::endl;
	using std::cin;

	int  rowCount = 2;
	int  colCount = 2;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	cout << endl;

	int suma = Sum(a, rowCount, colCount, 0, 0, 0);
	cout << endl;
	cout << "S = " << suma << endl;
	cout << endl;

	delete[] a;

	return 0;
}


void Create(int** a, const int rowCount, const int colCount, int i, int j)
{
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "a[" << i << "][" << j << "] = ";
	cin >> a[i][j];
	if (j < colCount - 1)
		Create(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Create(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl;
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	using std::cout;
	using std::endl;
	cout << std::setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
}

int Sum(int** a, const int rowCount, const int colCount, int i, int j1, int sum)
{
	if (a[i][j1] < 0)
	{
		for (int j = 0; j < colCount; j++)
			sum += a[i][j];
		j1 = colCount;
	}
	if (j1 < colCount - 1)
		Sum(a, rowCount, colCount, i, j1 + 1, sum);
	else
		if (i < rowCount - 1)
			return Sum(a, rowCount, colCount, i + 1, 0, sum);
		else
			return sum;
}
