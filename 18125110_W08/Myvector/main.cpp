#include<iostream>
#include<string>

using namespace std;

class MyVector {
private:
	int* a;
	int size;
public:
	MyVector();
	MyVector(int);
	class InvalidSizeException {};
	~MyVector();

};

MyVector::MyVector()
{
	size = 0;
	a = nullptr;
}

MyVector::MyVector(int n)
{
	if (n > 0)
		size = n;
	else
		throw InvalidSizeException();
	a = new int[size];
	for (int i = 0; i < size;++i)
		a[i] = 0;
}

MyVector::~MyVector()
{
	delete[]a;
	size = 0;
}


int main() {
	try {
		MyVector arr(-5);
	}
	catch (MyVector::InvalidSizeException)
		 {
		cout << "Error: A negative size was entered.\n";
		 }
	return 0;
}
