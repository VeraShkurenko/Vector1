#include "Vector.h"
#include<iostream>
#include <ctime>
#include<Windows.h>
using namespace std;

Vector::Vector()
{
	arr = nullptr;
	size = 0;
}
Vector::Vector(int s)
{
	size = s;
	arr = new int[size] {0};
}
Vector::~Vector()
{
	cout << "Destructor\n";
	delete[]arr;
	size = 0;
	
}
Vector::Vector(const Vector& obj)
{
	//cout << "Copy constructor\n";
	this->size = obj.size;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}

int* Vector::GetArr() const
{
	return arr;
}

int Vector::GetSize() const
{
	return size;
}

void Vector::SetSize(int s)
{
    size = s;
}

void Vector::SetArr(int* array)
{
    delete[] arr;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = array[i];
    }
}

void Vector::InputRand()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()%41 - 20; // [-20 +20]
	}
}
void Vector::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n---------------------------------------------------\n";
}

void Vector::PushBack(int a)
{
	int* temp = new int[size + 1];  // cодаем новый массив (тек размер +1)

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i]; // копируем текущие значения старого массива в новый массив
	}
	temp[size] = a; // инициализация последнего элемента параметром метода

	delete[] arr; // удаление старого массива!

	arr = temp; // перенаправляем указатель в объекте на новый дин. массив
	size++;

}

int Vector::PopBack()
{
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	int el = arr[size - 1]; // достаем последний элемент старого массива ДО удаления

	delete[] arr;
	arr = temp;
	size--;

	return el;
}

//Vector Vector::operator- (int a)
//{
//	Vector rez(size - a); // 5 - 2 = 3
//	for (int i = 0; i < rez.size; i++)
//	{
//		rez.arr[i] = this->arr[i];
//	}
//	return rez;
//}

Vector Vector::operator+(int a)
{
	Vector rez(size + a);
	for (int i = 0; i < size; i++)
	{
		rez.arr[i] = this->arr[i]; 
	}

	for (int i = size; i < rez.size; i++)
	{
		rez.arr[i] = 0;
	}

	return rez;
}


Vector Vector::operator+(Vector b)
{
	Vector rez(this->size + b.size);

	for (int i = 0; i < this->size; i++)
	{
		rez.arr[i] = this->arr[i];
	}

	for (int i = 0; i < b.size; i++)
	{
		rez.arr[this->size + i] = b.arr[i];
	}

	return rez;
}


Vector Vector::operator*(int a) {
	Vector rez(size); 
	for (int i = 0; i < size; i++)
	{
		rez.arr[i] = this->arr[i] * a; 
	}
	return rez;
}


Vector& Vector::operator++()
{
	int* temp = new int[size + 1];
	temp[0] = 0;

	for (int i = 0; i < size; i++)
	{
		temp[i + 1] = arr[i];
	}

	delete[] arr; 

	arr = temp; 
	size++;

	return *this;
}

Vector Vector::operator--(int)
{
	Vector temp = *this;

	if (size > 0)
	{
		int* newArr = new int[size - 1];

		for (int i = 0; i < size - 1; i++)
		{
			newArr[i] = arr[i + 1];
		}

		delete[] arr;
		arr = newArr;
		size--;
	}

	return temp;
}


Vector& Vector::operator--()
{
	if (size == 0) return *this; 

	int* temp = new int[size - 1]; 

	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i + 1]; 
	}

	delete[] arr;
	arr = temp;
	size--;

	return *this;
}


Vector Vector::operator++(int)
{
	Vector temp = *this;

	int* newArr = new int[size + 1];
	newArr[0] = 0;

	for (int i = 0; i < size; i++)
	{
		newArr[i + 1] = arr[i];
	}

	delete[] arr;
	arr = newArr;
	size++;

	return temp;
}



//Vector& Vector::operator+=(int a)
//{
//	int* temp = new int[size + a];
//
//	for (int i = 0; i < size; i++)
//	{
//		temp[i] = arr[i];
//	}
//
//	for (int i = size; i < size + a; i++)
//	{
//		temp[i] = 0;
//	}
//
//	delete[] arr;
//	arr = temp;
//	size += a;
//
//	return *this;
//}
//
//Vector& Vector::operator-=(int a)
//{
//	if (size >= a)
//	{
//		int* temp = new int[size - a];
//
//		for (int i = 0; i < size - a; i++)
//		{
//			temp[i] = arr[i];
//		}
//
//		delete[] arr;
//		arr = temp;
//		size -= a;
//	}
//
//	return *this;
//}
//
//Vector& Vector::operator*=(int a)
//{
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] *= a;
//	}
//	return *this;
//}
//
//Vector& Vector::operator/=(int a)
//{
//	if (a == 0) return *this;
//
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] /= a;
//	}
//	return *this;
//}

