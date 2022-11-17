#include <iostream>
#include <Windows.h>
using namespace std;

bool check(char sec, char frt, char sxt)
{
	if ((sec == 'à' || sec == 'è' || sec == 'î') && (frt == 'à' || frt == 'è' || frt == 'î') && (sxt == 'à' || sxt == 'è' || sxt == 'î'))
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
	a[0] = 'î';
	a[1] = 'à';
	a[2] = 'è';
	a[3] = 'ë';
	a[4] = 'ã';
	a[5] = 'ð';
	a[6] = 'ô';
	a[7] = 'ì';
	Razmbp(a, b, c);
}