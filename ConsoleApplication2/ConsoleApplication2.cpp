// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <clocale>
#include <iostream>

using namespace std;

//Тема: Шаблоны функций Задание.Реализуйте шаблонные функции для поиска максимума,
//	минимума, сортировки массива(любым алгоритмом сортировки), двоичного поиска в
//	массиве, замены элемента массива на переданное значение.


template <typename ToString>
void ArrayToString(const ToString * array, int length)
{
	for (short int i = 0; i < length; i++)
	{
		cout << "Arr[" << i << "] = " << array[i] << endl;
	}
	cout << endl;
}

template <typename Min>
void minValueInArray(const Min *array, int length)
{
	Min min = array[0];
	for (short int i = 0; i < length; i++)
	{
		if (min > array[i])
			min = array[i];
	}
	cout << "Minimal value is " << min << endl;
}

template <typename Max>
void maxValueInArray(const Max *array, int length)
{
	Max max = array[0];
	for (short int i = 0; i < length; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	cout << "Maximal value is " << max << endl;
}

template <typename SortToHigh>
void SortToHigher(SortToHigh *array, int length)
{
	for (short int i = 0; i < length; i++)
		for (short int j = length - 1; j >= i; j--)
			if (array[j] < array[i])
			{
				SortToHigh temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
	cout << "Sorting to higher value: " << endl;
	ArrayToString(array, length);
}

template <typename SortToLow>
void SortToLower(SortToLow *array, int length)
{
	for (short int i = 0; i < length; i++)
		for (short int j = length - 1; j >= i; j--)
			if (array[j] > array[i])
			{
				SortToLow temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
	cout << "Sorting to lower value: " << endl;
	ArrayToString(array, length);
}

template <typename Search>
void BinarySearch(Search *array, int length, int left, int right, int key)
{
	int middle = 0, index, i = 0;
	Search NewValue;

	bool flag = false;

	while ((left <= right) && (flag != true)) {
		middle = (left + right) / 2;

		if (array[middle] == key) flag = true;
		if (array[middle] > key) right = middle - 1;
		else left = middle + 1;
	}
	cout << "Enter index of element: ";
	cin >> index;

	if (flag) cout << "Index of element " << key << " in array: " << middle;
	else cout << "This value wasn't found in array.";
	cout << endl;

	cout << "Enter new value to change old: ";
	cin >> NewValue;

	array[index] = NewValue;

	ArrayToString(array, length);
	i++;
}


int main()
{
	setlocale(LC_ALL, "rus");

	// размеры массивов
	const int iSize = 10,
		dSize = 7,
		fSize = 10,
		cSize = 5;

	// массивы разных типов данных
	int    iArray[iSize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double dArray[dSize] = { 1.2345, 2.234, 3.57, 4.67876, 5.346, 6.1545, 7.7682 };
	float  fArray[fSize] = { 1.34f, 2.37f, 3.23f, 4.8f, 5.87f, 6.34f, 73.43f, 8.82f, 9.33f, 10.4f };
	char   cArray[cSize] = { "MARS" };

	cout << "\t\tPattern of function of an output of an array on the screen\n\n";

	// вызов локальной версии функции printArray для типа int через шаблон
	cout << "\n Array type int:\n"; ArrayToString(iArray, iSize);

	// вызов локальной версии функции printArray для типа double через шаблон
	cout << "\n Array type double:\n"; ArrayToString(dArray, dSize);

	// вызов локальной версии функции printArray для типа float через шаблон
	cout << "\n Array type float:\n"; ArrayToString(fArray, fSize);

	// вызов локальной версии функции printArray для типа char через шаблон
	cout << "\n Array type char:\n"; ArrayToString(cArray, cSize);

	system("pause");
	system("cls");

	minValueInArray(iArray, iSize);
	minValueInArray(dArray, dSize);
	minValueInArray(fArray, fSize);
	minValueInArray(cArray, cSize);

	cout << endl;
	system("pause");
	system("cls");


	maxValueInArray(iArray, iSize);
	maxValueInArray(dArray, dSize);
	maxValueInArray(fArray, fSize);
	maxValueInArray(cArray, cSize);

	cout << endl;
	system("pause");
	system("cls");

	SortToHigher(iArray, iSize);
	SortToHigher(dArray, dSize);
	SortToHigher(fArray, fSize);
	SortToHigher(cArray, cSize);

	cout << endl;
	system("pause");
	system("cls");

	SortToLower(iArray, iSize);
	SortToLower(dArray, dSize);
	SortToLower(fArray, fSize);
	SortToLower(cArray, cSize);

	cout << endl;
	system("pause");
	system("cls");

	int key;
	int left = iSize / 2, right = left;
	cout << "Enter value, which you want to find: ";
	cin >> key;

	cout << "Old array: " << endl;
	ArrayToString(iArray, iSize);
	cout << endl;

	cout << "New array: " << endl;
	BinarySearch(iArray, iSize, left, right, key);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Old array: " << endl;
	ArrayToString(fArray, fSize);
	cout << endl;

	BinarySearch(fArray, fSize, left, right, key);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Old array: " << endl;
	ArrayToString(dArray, dSize);
	cout << endl;

	BinarySearch(dArray, dSize, left, right, key);
	cout << endl;
	system("pause");
	system("cls");

	cout << "Old array: " << endl;
	ArrayToString(cArray, cSize);
	cout << endl;

	BinarySearch(cArray, cSize, left, right, key);
	cout << endl;

	return 0;
	exit(1);
}