#pragma once
#include<iostream>
#include<string>
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
	void operator=(T src);
	int compare(T a, T b);
	void swap(T&a, T&b);

};

template<class T>
void MyVector<T>::operator=(T src)
{
	arr = src;
}
template<class T>
int MyVector<T>::compare(T a, T b)
{
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
}
template<class T>
void MyVector<T>::swap(T & a, T & b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
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
void MyVector<T>::toArray(T * arr1, int & n)
{
	delete[] arr1;
	arr1 = new T[size];
	for (int i = 0; i < size; i++)
		arr1[i] = arr[i];
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
	for (int i = 0; i < size; i++) {
		if (arr[i] == value)
			return i;
	}
	return -1;
}
template<class T>
void MyVector<T>::addRange(T * a, int n)
{
	MyVector tmp(arr);
	arr = new T[size + n];
	for (int i = 0; i < size; i++) {
		arr[i] = tmp[i];
	}
	for (int j= size; j < size + n; j++) {
		 arr[j]=a[j-size];
	}
	size += n;
	delete[] tmp;
	tmp = nullptr;
	
}
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
template<class T>
int MyVector<T>::lastIndexOf(T value)
{
	return value.getSize();
}
template<class T>
void MyVector<T>::insert(T value, int index)
{
	if (index > size)
		return;
	T tmp_ = arr[index];
	T *tmp = new T[size];
	for (int i = 0; i < size; i++)
		tmp[i] = arr[i];
	delete[]arr;
	arr = new T[size + 1];
	for (int i = 0; i < index; i++) {
		arr[i] = tmp[i];
	}
	arr[index] = value;
	arr[index + 1] = tmp_;
	for (int j = size; j > index + 1; j--) {
		arr[j] = tmp[j - 1];
	}
	size += 1;
	delete[] tmp;
	tmp = nullptr;
}
template<class T>
void MyVector<T>::remove(T value)
{
	int tmp = indexOf(value);
	if (tmp != -1) {
		for (int i = tmp; i < size; i++)
			arr[i] = arr[i + 1];
		arr[size - 1] = 0;
		size = size - 1;
	}

}
template<class T>
void MyVector<T>::removeAt(int index)
{
	if (index >= size)
		return;
	for (int i = index; i < size; i++)
		arr[i] = arr[i + 1];
	arr[size - 1] = 0;
	size = size - 1;
}
template<class T>
void MyVector<T>::reverse()
{
	T *tmp = new T[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	for (int j = 0; j < size; j++) {
		arr[j] = tmp[size - 1 - j];
	}
}
template<class T>
string MyVector<T>::toString()
{
	string ret = "";
	for (int i = 0; i < size; i++)
		ret += to_string(arr[i]);
	return ret;
}
template<class T>
void MyVector<T>::sortAsc()
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (compare(arr[j], arr[j + 1]) == 1)
				swap(arr[j], arr[j + 1]);
}
template<class T>
void MyVector<T>::sortDesc()
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (compare(arr[j], arr[j + 1]) == -1)
				swap(arr[j], arr[j + 1]);
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
	void operator=(Fraction a);
	bool operator>(Fraction a);
	bool operator<(Fraction a);
	int getNu() { return nu; }
	int getDe() { return de; }
	
};
void Fraction::operator=(Fraction a)
{
	nu = a.nu;
	de = a.de;
}
bool Fraction::operator>(Fraction a)
{
	if (nu*a.de - de * a.nu > 0)
		return true;
	return false;
}
bool Fraction::operator<(Fraction a)
{
	if (nu*a.de - de * a.nu < 0)
		return true;
	return false;
}
string to_string(Fraction a)
{
	string tmp = "";
	tmp = to_string(a.getNu()) + "/" + to_string(a.getDe())+"-";
	return tmp;
}
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
	v1.insert(25, 1);
	v1.print();
	v1.add(30);
	v1.add(35);
	v1.add(40);
	v1.print();
	cout << "'remove: \n";
	v1.remove(30);
	v1.print();
	cout << "reverse:\n";
	v1.reverse();
	v1.print();

	v1.removeAt(5);
	v1.print();


	v1.sortAsc();
	v1.print();
	cout << v1.toString() << endl;
	MyVector<Fraction> v2;
	v2.print();
	v2.add(10);
	v2.print();

	v2.add(20);
	v2.print();

	v2.insert(15, 1);
	v2.print();

	v2.add(45);
	v2.add(50);
	v2.insert(55, 1);
	v2.print();
	v2.sortAsc();
	v2.print();
	v2.sortDesc();
	v2.print();
	cout << v2.toString() << endl;
	system("pause");
	return 0;
}

