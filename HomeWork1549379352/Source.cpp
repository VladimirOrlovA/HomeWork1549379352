﻿#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void FillArrayOrder(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = i;
}


void FillArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 1 + rand() % 9;
}

void FillArray(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = float(1 + rand() % 5) / (2 + rand() % 3);
		arr[i] = float(int(arr[i] * 100) % 100) / 100;
	}
}

void FillArray(char arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 256;
}


void PrintArray(int arr[], int n)
{
	cout << endl << endl;

	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}

void PrintArray(float arr[], int n)
{
	cout << endl << endl;

	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}

void PrintArray(char arr[], int n)
{
	cout << endl << endl;

	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}

template<typename T>
void SearchMax(T arr[], int n, T x)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > x) count++;
	}

	cout << "Кол-во элементов больше " << x << " =>  " << count << endl << endl;
}

template<typename T>
void ReorderingArray(T arr[], int n)
{
	T c;
	for (int i = 0; i < n / 2; i++)
	{
		c = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = c;
	}
}

void InvertDigits(int& k)
{
	int buf, i = 0, s = 0;

	buf = k;

	// Определяем разрядность числа для последующего перевода цифр в обратном порядке

	while (buf > 0)
	{
		buf /= 10;
		i++;
	}
	
	// Переводим введенное число в обратном порядке

	while (i >= 0)
	{
		if (k % 10 == 0) k *= 10;
		s += k % 10 * pow(10, i - 1);
		k /= 10;
		i--;
	}

	cout <<"Invert number \t\t"<< s << endl;
	
}

void AddRightDigit(int& k, int d)
{
	
	// Добавляем к введенному числу k справа число d

	k = k * 10 + d;

	cout << "\nAdded digit to the number \t" << k << endl;

}

void AddLeftDigit(int& k, int d)
{
	// Определяем разрядность числа для последующего подстановки цифры слева

	int b, i = 0;

	b = k;
	while (b > 0)
	{
		b/= 10;
		i++;
	}
	
	// Добавляем к введенному числу k слева число d

	k += (pow(10, i) * d);

	cout << "\nAdded digit to the number \t" << k << endl;

}


void Task1()
{
	//	Proc7.Описать процедуру InvertDigits(K), меняющую порядок следования цифр целого положительного числа K на обратный
	//	(K — параметр целого типа, являющийся одновременно входным и выходным). С помощью этой процедуры поменять порядок 
	//	следования цифр на обратный для каждого из пяти данных целых чисел.

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int count = 0, k;

	while (count < 5)
	{
		cout << "\nEnter " << count + 1 << " number -> \t";
		cin >> k;
		InvertDigits(k);
		count++;
	}

}

void Task2()
{
	//	Proc8◦.Описать процедуру AddRightDigit(D, K), добавляющую к целому положительному числу K справа цифру D(D — входной 
	//	параметр целого типа, лежащий в диапазоне 0–9, K — параметр целого типа, являющийся одновременно входным и выходным).
	//	С помощью этой процедуры последовательно добавить к данному числу K справа данные цифры D1 и D2, выводя результат 
	//	каждого добавления.
	
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int count = 0, k = 0, d = 0;
	char flag = 'n';

	cout << "\nEnter number k -> \t\t";
	cin >> k;
	
	do
	{
		int check = 1;

		do
		{
			cout << "\nEnter digit d" << count + 1 << " from 0 to 9 -> \t";
			cin >> d;
			
			if (d >= 0 && d <= 9) check = 0;
			else cout << "\nWrong input, try again \n" << endl;
		
		} while (check);

		count++;

		AddRightDigit(k, d);

		cout << "\n\nDo You want enter one more digit? (y/n) -> ";
		cin >> flag;

	} while (flag == 'y');

}

void Task3()
{
	//	Proc9.Описать процедуру AddLeftDigit(D, K), добавляющую к целому положительному числу K слева цифру D(D — входной параметр
	//	целого типа, лежащий в диапазоне 1–9, K — параметр целого типа, являющийся одновременно входным и выходным).С помощью этой 
	//	процедуры последовательно добавить к данному числу K слева данные цифры D1 и D2, выводя результат каждого добавления.

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int count = 0, k = 0, d = 0;
	char flag = 'n';

	cout << "\nEnter number k -> \t\t";
	cin >> k;

	do
	{
		int check = 1;

		do
		{
			cout << "\nEnter digit d" << count + 1 << " from 1 to 9 -> \t";
			cin >> d;

			if (d >= 1 && d <= 9) check = 0;
			else cout << "\nWrong input, try again \n" << endl;

		} while (check);

		count++;

		AddLeftDigit(k, d);

		cout << "\n\nDo You want enter one more digit? (y/n) -> ";
		cin >> flag;

	} while (flag == 'y');

}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n  05_02_2019 Evening  1549379352 \n\n";
	SetConsoleTextAttribute(hConsole, 7);
	

	setlocale(LC_ALL, "");
	srand(time(NULL));

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (3) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;
		case 3: {Task3(); } break;

		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO any keys => ";
		cin >> flag;

	} while (flag == 'y');
}
