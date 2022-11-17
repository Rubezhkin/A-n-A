#include <iostream>
#include <Windows.h>
using namespace std;

bool check(char sec, char frt, char sxt)
{
	if ((sec == '�' || sec == '�' || sec == '�') && (frt == '�' || frt == '�' || frt == '�') && (sxt == '�' || sxt == '�' || sxt == '�'))
		return true;
	else return false;
}

void Razmbp(char* a, bool* b, char* c, int n = 0)
{
	if (n == 8)
	{
		if (check(c[1], c[3], c[5]))
		{
			for (int i = 0; i < 8; i++)
				cout << c[i];
			cout << "\n";
		}
	}
	else
		for(int i = 0; i < 8; i++)
			if (b[i])
			{
				c[n] = a[i];
				b[i] = false;
				Razmbp(a,b,c, n+1);
				b[i] = true;
			}
}


void main()
{
	SetConsoleOutputCP(1251);
	int k = 8;
	char* a = new char[k];
	bool* b = new bool[k];
	char* c = new char[k];
	for (int i = 0; i < 8; i++)
	{
		c[i] = ' ';
		b[i] = true;
	}
	a[0] = '�';
	a[1] = '�';
	a[2] = '�';
	a[3] = '�';
	a[4] = '�';
	a[5] = '�';
	a[6] = '�';
	a[7] = '�';
	Razmbp(a, b, c);
}