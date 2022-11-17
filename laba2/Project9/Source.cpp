#include <iostream>
using namespace std;

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << "\n";
}

void copy(int* arr1, int a, int b, int* arr2, int k)
{
	for (int i = a; i < b; i++)
	{
		arr2[k] = arr1[i];
		k++;
	}
}

void Merge(int* res, int st_in, int f_len, int sec_len)
{
	int* a = new int[f_len + sec_len];
	int  i, j, k;
	i = st_in;
	j = st_in + f_len;
	k = 0;
	while (i != st_in+f_len && j != st_in+f_len+sec_len)
	{
		if (res[i] < res[j])
		{
			a[k] = res[i];
			i++;
		}
		else
		{
			a[k] = res[j];
			j++;
		}
		k++;
	}
	if (i == st_in + f_len)
		copy(res, j, st_in + f_len + sec_len, a, k);
	else
		copy(res, i, st_in + f_len, a, k);
	copy(a, 0, f_len + sec_len, res, st_in);
}

void func(int** arr, int n, int m) // попытка сделать O(nm*log(n))
{
	int arr_len = n * m;
	int* result = new int[arr_len];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result[i * m + j] = arr[i][j];
	int len = m;
	while (len < arr_len)
	{
		for (int i = 0; i < arr_len; i += len * 2)
			Merge(result, i, min(len, (arr_len-i)), min(len, max(0,arr_len - i - len)));
		len *= 2;
		print(result, arr_len);
	}
	print(result, arr_len);
}

void main()
{
	int n, m;
	cin >> n >> m;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	func(arr, n, m);
}