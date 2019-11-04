#include "Fraction.h"

Fraction::Fraction()
{
	nu = 0;
	de = 1;
}

Fraction::Fraction(int a, int b)
{
	nu = a;
	de = b;
}

Fraction::Fraction(int a)
{
	nu = a;
	de = 1;
}

void Fraction::operator=(Fraction a)
{
	nu = a.nu;
	de = a.de;
}

Fraction Fraction::operator+(const Fraction &a)
{
	Fraction tmp;
	tmp.nu = nu * a.de + de * a.nu;
	tmp.de = de * a.de;
	tmp.reduce();
	return tmp;
}

Fraction Fraction::operator-(const Fraction &a)
{
	Fraction tmp;
	tmp.nu = nu * a.de - de * a.nu;
	tmp.de = de * a.de;
	tmp.reduce();
	return tmp;
}

Fraction Fraction::operator*(const Fraction &a)
{
	Fraction tmp;
	tmp.nu = nu * a.nu;
	tmp.de = de * a.de;
	tmp.reduce();
	return tmp;
}

Fraction Fraction::operator/(const Fraction &a)
{
	Fraction tmp;
	tmp.nu = nu * a.de;
	tmp.de = de * a.nu;
	tmp.reduce();
	return tmp;
}

Fraction& Fraction::operator+=(const Fraction & a)
{
	nu = nu * a.de + de * a.nu;
	de = de * a.de;
	reduce();
	return *this;
}

Fraction & Fraction::operator-=(const Fraction & a)
{
	nu = nu * a.de - de * a.nu;
	de = de * a.de;
	reduce();
	return *this;
}

Fraction & Fraction::operator*=(const Fraction & a)
{
	nu = nu * a.nu;
	de = de * a.de;
	reduce();
	return *this;
}

Fraction & Fraction::operator/=(const Fraction & a)
{
	nu = nu * a.de;
	de = de * a.nu;
	reduce();
	return *this;
}

Fraction & Fraction::operator++()
{
	nu = nu + de;
	return *this;
}

Fraction  Fraction::operator++(int)
{
	Fraction tmp(*this);
	nu = nu + de;
	return tmp;
}

Fraction & Fraction::operator--()
{
	nu = nu - de;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction tmp(*this);
	nu = nu + de;
	return tmp;
}

bool Fraction::operator<(Fraction a)
{
	if (nu * a.de - de * a.nu < 0)
		return true;
	return false;
}

bool Fraction::operator>(Fraction a)
{
	if (nu * a.de - de * a.nu > 0)
		return true;
	return false;
}

bool Fraction::operator<=(Fraction a)
{
	if (nu * a.de - de * a.nu <= 0)
		return true;
	return false;
}

bool Fraction::operator>=(Fraction a)
{
	if (nu * a.de - de * a.nu >= 0)
		return true;
	return false;
}

bool Fraction::operator==(Fraction a)
{

	if (nu * a.de - de * a.nu == 0)
		return true;
	return false;
}

bool Fraction::operator!=(Fraction a)
{

	if (nu * a.de - de * a.nu != 0)
		return true;
	return false;
}

int Fraction::findGCD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a == 0 || b == 0) {
		return a + b;
	}
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		if (b > a)
		{
			b -= a;
		}
	}
	return a;
}

void Fraction::reduce()
{
	if (nu < 0 && de < 0) {
		nu *= -1;
		de *= -1;
	}
	int tmp = findGCD(nu, de);
	nu = nu / tmp;
	de = de / tmp;
}

Fraction::operator float()
{
	return (float)nu / (float)de;
}

Fraction::~Fraction()
{
}

ostream & operator<<(ostream & cout, const Fraction & a)
{
	cout << a.nu << "/" << a.de << endl;
	return cout;
}

Fraction operator*(const Fraction & a, const Fraction & b)
{
	Fraction tmp(a);
	tmp *= b;
	return tmp;
}

Fraction operator-(const Fraction & a, const Fraction & b)
{
	Fraction tmp;
	tmp = a - b;
	return tmp;
}

Fraction operator+(const Fraction & a, const Fraction & b)
{
	Fraction tmp(a);
	tmp += b;
	return tmp;
}


