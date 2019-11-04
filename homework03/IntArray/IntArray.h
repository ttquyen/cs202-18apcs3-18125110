#pragma once
#include<iostream>
using namespace std;
class IntArray
{
public:
	IntArray();
	IntArray(int n_);
	IntArray(int *a, const int &n_);
	IntArray(const IntArray &b);
	~IntArray();
	IntArray& operator=(const IntArray &b);
	friend istream& operator>>(istream &cin, IntArray &x);
	friend ostream& operator<<(ostream &cout, const IntArray &x);
	int &operator[](int i);
	operator int();
private:
	int *arr;
	int n;
};

