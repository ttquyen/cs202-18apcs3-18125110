// YY: 10
#include"IntArray.h"

int main()
{
	// Using dynamic allocated array: int *arr, n;
	IntArray m1;
	IntArray m2(7);
	int a[100];
	int n = 7;
	for(int i = 0; i < n; i++)
	{
		a[i] = i * 10;
	}
	cout << m2;
	IntArray m3(a, n);
	IntArray m4(m2);

	IntArray m5;
	m5=m2;
	
	cin >> m2;

	cout << m2;

	cout << m3[6] << endl;;
	m3[6] = 1;

	cout << (int)m4 << endl; // sum of all elements
	system("pause");
	return 0;
}
