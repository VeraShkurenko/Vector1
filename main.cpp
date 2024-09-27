#include<iostream>
#include"Vector.h"
using namespace std;

Vector operator +=(Vector& obj, int a)
{
	int newSize = obj.GetSize() + a;
	int* newArr = new int[newSize];

	for (int i = 0; i < obj.GetSize(); i++)
	{
		newArr[i] = obj.GetArr()[i];
	}

	for (int i = obj.GetSize(); i < newSize; i++)
	{
		newArr[i] = 0;
	}


	obj.SetArr(newArr);
	obj.SetSize(newSize);
	delete[] newArr;

	return obj;
}

Vector operator -=(Vector& obj, int a)
{
	if (obj.GetSize() >= a)
	{
		int newSize = obj.GetSize() - a;
		int* newArr = new int[newSize];

		for (int i = 0; i < newSize; i++)
		{
			newArr[i] = obj.GetArr()[i];
		}

		obj.SetArr(newArr);
		obj.SetSize(newSize);
		delete[] newArr;
	}

	return obj;
}

Vector operator *=(Vector& obj, int a)
{
	for (int i = 0; i < obj.GetSize(); i++)
	{
		obj.GetArr()[i] = a;
	}

	return obj;
}



Vector operator -(Vector& obj, int a)
{
	if (a >= obj.GetSize())
	{
		return Vector(0);  
	}

	int newSize = obj.GetSize() - a;
	int* newArr = new int[newSize];

	for (int i = 0; i < newSize; i++)
	{
		newArr[i] = obj.GetArr()[i + a];
	}

	Vector newVector(newSize);
	newVector.SetArr(newArr);
	delete[] newArr;

	return newVector;
}


ostream& operator<<(ostream& os, Vector& obj)
{
	for (int i = 0; i < obj.GetSize(); i++)
	{
		os << obj.GetArr()[i] << " ";
	}
	return os;

}

istream& operator>>(istream& is, Vector& obj)
{
	for (int i = 0; i < obj.GetSize(); i++)
	{
		is >> obj.GetArr()[i];
	}
	return is;

}


int main()
{
	srand(time(0));

	Vector obj1(5); 
	obj1.InputRand();
	obj1.Print();

	{

		//Vector obj3 = obj1 - 2;// 1 2 3    
		//obj3.Print();
		//obj1.Print();

		//Vector obj2 = obj1 + 5; // 1 2 3 4 5 0 0 0 0 
		//obj2.Print();
		//obj1.Print();


		//Vector obj4(2);// 10 20
		//obj4.InputRand();
		//Vector obj5 = obj1 + obj4; // 1 2 3 4 5 10 20
		//obj4.Print();
		//obj5.Print();


		//Vector obj6 = obj1 * 3; // 3 6 9 12 15 
		//obj6.Print();
	}


    ++obj1;
	obj1.Print();

	--obj1;
	obj1.Print();


	Vector obj2 = ++obj1;
	obj1.Print();
	obj2.Print();

	--obj1;
	obj1.Print();


	Vector obj3 = obj1++;
	obj3.Print();
	obj1.Print();



	Vector obj4(3);
	obj4.InputRand();
	obj4.Print();

	obj4 += 5;
	obj4.Print();
	obj4 -= 5;
	obj4.Print();
	obj4 *= 5;
	obj4.Print();


	cout << obj4;

	

}


/*
*
* Vector obj4 = ++obj1; // obj4 = 0 1 2 3 4 5   obj1 = 0 1 2 3 4 5
* Vector obj5 = obj1++; // obj5 = 1 2 3 4 5     obj1 = 0 1 2 3 4 5
*  так же и декремент(obj5--, --ob5)
* Vector obj6(3); // 1 2 3
* obj6+=5; // 1 2 3 0 0 0 0 0
* obj6-=5; // количество уменьшаем на 5 если тек. размер >=5,иначе ничего не делаем
* obj6*=5; // каждый элемент умножаем на 5, возвращаем массив после изменения

*/