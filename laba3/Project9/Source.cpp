#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;


void DSF(int** arr, int size, bool* flag, int in)
{
	flag[in] = 1;
	for (int i = 0; i < size; i++)
		if (!flag[i]&&arr[in][i]==1)
			DSF(arr, size, flag, i);
}

int task(Graph& Gr)
{
	int n = Gr.getsize();
	bool* flag = new bool[n];
	for (int i = 0; i < n; i++)
		flag[i] = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if (!flag[i])
		{
			cnt++;
			DSF(Gr.getmatrix(), n, flag, i);
		}
	return --cnt;
}

void main()
{
	int size, cnt;
	fstream file("data.txt");
	file >> size >> cnt;
	Graph Gr(size);
	int n1, n2;
	for (int i = 0; i < cnt; i++)
	{
		file >> n1 >> n2;
		Gr.add_edge(n1 - 1, n2 - 1);
	}

	cout << task(Gr);
}