#pragma once
#include <iostream> 
using namespace std;

class Vector
{
	int* arr;
	int size;
	friend ostream& operator<< (ostream& os, Vector& obj);
	friend istream& operator>> (istream& is, Vector& obj);
public:
	Vector();
	~Vector();
	Vector(const Vector & obj);

	Vector(int s);
	void InputRand(); // инициализация случ числами
	void Print();// вывод на консоль

	void PushBack(int a);
	int PopBack();


	int* GetArr() const; 
	int GetSize() const;

	void SetSize(int s);
	void SetArr(int* array);

	/// перегрузки операции
	//Vector operator-(int a);
	Vector operator+(int a);
	Vector operator+(Vector b);
	Vector operator*(int a);

	Vector& operator++();
	Vector operator++(int);
	 
	Vector& operator--();
	Vector operator--(int);

	//Vector& operator+=(int a);
	//Vector& operator-=(int a);
	//Vector& operator*=(int a);
	//Vector& operator/=(int a);

};
