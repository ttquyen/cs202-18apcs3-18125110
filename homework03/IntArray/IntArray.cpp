#include "IntArray.h"

IntArray::IntArray()
{
	n = 0;
	arr = nullptr;
}

IntArray::IntArray(int n_)
{
	n = n_;
	delete[] arr;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}

IntArray::IntArray(int *a, const int &n_)
{
	n = n_ >= 0 ? n_ : 0;
	delete[] arr;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = a[i];
	}
}

IntArray::IntArray(const IntArray & b)
{
	n = b.n;

	delete[] arr;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = b.arr[i];
	}
}

IntArray& IntArray::operator=(const IntArray &b)
{
	n = b.n;
	delete[] arr;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = b.arr[i];
	}
	return (*this);
}

IntArray::~IntArray()
{
	if (arr != nullptr)
	{
		arr = nullptr;
		delete[] arr;
		n = 0;
	}
}

istream & operator>>(istream & cin, IntArray & x)
{
	do {
		cout << "Please input n: ";
		cin >> x.n;
	} while (x.n < 0);
	delete[] x.arr;
	x.arr = new int(x.n);
	for (int i = 0; i < x.n; i++) {
		cout << "arr[" << i << "] = ";
		cin >> x.arr[i];
	}
	return cin;
}

ostream & operator<<(ostream & cout, const IntArray & x)
{
	cout << "-----Elements:------\n";
	for (int i = 0; i < x.n; i++) {
		cout << "arr[" << i << "] = " << x.arr[i] << endl;
	}
	return cout;
}

int &IntArray::operator[](int i)
{
	if (i < 0 || i >= n)
		cout << "i does not belong in the array! " << endl;
	return arr[i];
}

IntArray::operator int()
{
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += arr[i];
	}
	return tmp;
}
