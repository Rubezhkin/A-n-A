#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int f(int* arr, int n)
{
	int result = 0;
	int in1 = 0, in2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			result = max(result, i - min(in1, in2));
			if (arr[i] == 1)
				in1 = in2 = i;
			else if (in1 > in2)
				in2 = i;
			else
				in1 = i;	
		}
	}
	return result;
}

int task(fstream& file)
{
	int k, len;
	file >> k >> len;
	string stone;
	int* arr = new int[len + 1];
	arr[0] = arr[len] = 1;
	for (int i = 1; i < len; i++) arr[i] = 0;
	for (int i = 0; i < k; i++)
	{
		file >> stone;
		int index = 0;
		for (int j = 2; j < stone.length(); j++)
			index = index * 10 + stone[j] - '0';
		if (stone[0] == 'B') arr[index] = 1;
		else arr[index] = -1;
	}
	return f(arr, len + 1);
}

void main()
{
	fstream file("data.txt");
	int cnt;
	file >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cout << "case " << i + 1 << ": " << task(file) << "\n";
	}
}