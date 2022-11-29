#include <iostream>
#include <fstream>

using namespace std;

void print(int** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}

int findmax(int* a, int n)
{
	if (n == 1)return a[0];
	int* b = new int[n];
	for (int i = 0; i < n; i++) b[i] = a[i];
	int maxb = a[n / 2 - 1]; int maxe = a[n / 2];
	int res;
	for (int i = n / 2 - 2; i >= 0; i--)
	{
		b[i] += b[i + 1];
		if (maxb < b[i])
			maxb = b[i];
	}
	for (int i = n / 2 + 1; i < n; i++)
	{
		b[i] += b[i - 1];
		if (maxe < b[i])
			maxe = b[i];
	}
	if (maxe < 0)
	{
		int* c = new int[n / 2];
		for (int i = 0; i < n / 2; i++) c[i] = a[i];
		return findmax(c, n / 2);
	}
	else if (maxb < 0)
	{
		int* c = new int[n / 2 + n % 2];
		for (int i = n / 2; i < n; i++) c[i - n / 2] = a[i];
		return findmax(c, n / 2 + n % 2);
	}
	return maxb + maxe;
}


int task(int** arr, int n)
{
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] += arr[i - 1][j];
	//print(arr, n, n);
	int* k = new int[n];
	int res = 0;

	for(int i = 0; i < n; i++)
		for (int j = 0; j <= i ; j++)
		{
			if (j == 0)
				for (int a = 0; a < n; a++)
					k[a] = arr[i][a];
			else
				for (int a = 0; a < n; a++)
					k[a] = arr[i][a]-arr[j-1][a];
			res = max(res, findmax(k, n));
		}
	return res;
}

void main()
{
	int n;
	cin >> n;
	ifstream file("data.txt");

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
			file >> arr[i][j];
	}
	//print(arr, n, n);
	cout << task(arr, n);
}