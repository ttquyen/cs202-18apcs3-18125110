#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyVector
{
private:
	T *arr;
	int size;
public:
	MyVector();
	~MyVector();
	MyVector(int n);
	MyVector(T *a, int n);
	MyVector(const MyVector &v);
	int getSize();
	T getItem(int index);
	void setItem(T value, int index);
	void print();
	void add(T value);
	void addRange(T *a, int n);
	void clear();
	bool contains(T value);
	void toArray(T *arr, int &n);
	bool equals(const MyVector &v);
	int indexOf(T value);
	int lastIndexOf(T value);
	void insert(T value, int index);
	void remove(T value);
	void removeAt(int index);
	void reverse();
	string toString();
	void sortAsc();
	void sortDesc();
};


template<class T>
MyVector<T>::MyVector()
{
	size = 0;
	arr = nullptr;
}

template<class T>
MyVector<T>::~MyVector()
{
	size = 0;
	delete[] arr;
	arr = nullptr;
}

template<class T>
int MyVector<T>::getSize()
{
	return size;
}

template<class T>
T MyVector<T>::getItem(int index)
{
	return arr[index];
}

template<class T>
void MyVector<T>::setItem(T value, int index)
{
	arr[index] = value;
}

template<class T>
void MyVector<T>::print()
{
	if (size == 0) {
		cout << "Empty array" << endl;
	}
	else {
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
}

template<class T>
void MyVector<T>::add(T value)
{
		T *b = new T[size + 1];
		for (int i = 0; i < size; i++) {
			b[i] = arr[i];
		}
		b[size] = value;
		delete[]arr;
		arr = b;
		size++;
	
}

template<class T>
void MyVector<T>::clear()
{
	delete[]arr;
	arr = nullptr;
	size = 0;
}

template<class T>
bool MyVector<T>::contains(T value)
{
	if (indexOf(value) != -1)
		return true;
	return false;
}

template<class T>
bool MyVector<T>::equals(const MyVector & v)
{
	if(size!=v.size)
	return false;
	else {
		for (int i = 0; i < size; i++) {
			if (arr[i] != v.arr[i])
				return false;
		}
	}
	return true;
}

template<class T>
int MyVector<T>::indexOf(T value)
{
	for (i = 0; i < size; i++) {
		if (arr[i] == value)
			return i;
	}
	return -1;
}

//template<class T>
//void MyVector<T>::addRange(T * a, int n)
//{
//	//int size_ = n;
//	T *tmp = new T[size+n];
//	for (int i = 0; i < size; i++) {
//		tmp[i] = this[i];
//	}
//	for (int j= size; j < size + n; j++) {
//		tmp[j] = a[j-size];
//	}
//	this = nullptr;
//	size += n;
//	
//}

template<class T>
MyVector<T>::MyVector(int n)
{
	size = n;
	arr = new T[size];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}

template<class T>
MyVector<T>::MyVector(T * a, int n)
{
	size = n;
	arr = nullptr;
	arr = new T[size];
	for (int i = 0; i < n; i++)
		arr[i] = a[i];
}

template<class T>
MyVector<T>::MyVector(const MyVector & v)
{
	size = v.size;
	arr = nullptr;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = v[i];
}

class Fraction {
private:
	int nu;
	int de;
public:
	Fraction();
	Fraction(int);
	Fraction(int, int);
	void print();
	
};

Fraction::Fraction()
{
	nu = 0;
	de = 1;
}

Fraction::Fraction(int a)
{
	nu = a;
	de = 1;
}

Fraction::Fraction(int a, int b)
{
	nu = a;
	de = b;
}

void Fraction::print()
{
	cout << nu << "/" << de << " ";
}
ostream & operator<<(ostream & cout, Fraction & a)
{
	a.print();
	return cout;
}

int main() {

	MyVector<int> v1;
	v1.print();

	v1.add(10);
	v1.print();

	v1.add(20);
	v1.print();
	MyVector<Fraction> v2;
	v2.print();
	v2.add(10);
	v2.print();

	v2.add(20);
	v2.print();
	system("pause");
	return 0;
}

template<class T>
int MyVector<T>::lastIndexOf(T value)
{
	return value.getSize();
}

template<class T>
void MyVector<T>::reverse()
{
	T *tmp = new t[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = this[i];
	}
	for (int j = 0; j < size; j++) {
		this[j]=tmp[size-1-j];
	}
}
