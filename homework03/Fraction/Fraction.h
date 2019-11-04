#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

class Fraction
{
public:
	Fraction();
	Fraction(int a, int b);
	Fraction(int a);
	friend ostream& operator<<(ostream &cout, const Fraction &a);
	void operator=(Fraction a);

	Fraction operator+(const Fraction &a);
	Fraction operator-(const Fraction &a);
	Fraction operator*(const Fraction &a);
	Fraction operator/(const Fraction &a);

	Fraction& operator+=(const Fraction &a);
	Fraction& operator-=(const Fraction &a);
	Fraction& operator*=(const Fraction &a);
	Fraction& operator/=(const Fraction &a);

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	bool operator<(Fraction a);
	bool operator>(Fraction a);
	bool operator<=(Fraction a);
	bool operator>=(Fraction a);
	bool operator==(Fraction a);
	bool operator!=(Fraction a);

	int findGCD(int a, int b);
	void reduce();

	explicit operator float();
	~Fraction();
private:
	int nu;
	int de;
};
Fraction operator*(const Fraction &a, const Fraction &b);
Fraction operator-(const Fraction & a, const Fraction & b);
Fraction operator+(const Fraction &a, const Fraction &b);



