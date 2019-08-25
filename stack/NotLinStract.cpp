#include <iostream>
#include "CustomStack.h"

using namespace std;


//Сортировка подсчетом сравнений для массива
void sorts(int *in, int*out, int u, int v, int n)
{
	int *count = new int [v+1];
	for(int i = 0; i < n; i++)
		count[i] = 0;
	
	for(int i = 0; i < n; i++)
		count[in[i]]++;
	
	for(int i = u+1; i <= v; i++)
		count[i] += count[i-1];
	
	int i = 0;
	for(int j = n-1; j >= 0; j--)
	{
		i = count[in[j]];
		out[i-1] = in[j];
		count[in[j]] = --i;
	}
}
//Сортировка посчетом сравнений для прегруженного стека
void sort(CustomStack &in, CustomStack &out, int u, int v, int n)
{
	CustomStack count;
	for(int i = 0; i < n; i++)
		count.push(0);
	
	for(int i = 0; i < n; i++)
		count.set_item(in.get_item(i), count.get_item(in.get_item(i)) + 1);
	
	for(int i = u+1; i <= v; i++)
		count.set_item(i, count.get_item(i) + count.get_item(i-1));
	
	int i = 0;
	for(int j = n-1; j >= 0; j--)
	{
		i = count.get_item(in.get_item(j));
		out.set_item(i-1, in.get_item(j));
		count.set_item(in.get_item(j), i-1);
	}	
}


int main()
{
	/////////////
 	CustomStack toSort;
	CustomStack out;
	
	int n = 10;
	int u = 1;
	int v = 5;
	int data[] = {2,5,1,2,2,4,1,1,1,3};
	for(int i = 0; i < n; i++)
	{
		toSort.push(data[i]);
		out.push(0);
	}
	
	cout << "in:  ";
	for (int i = 0; i< n; i++)
		cout << toSort.get_item(i) << ' ';
	cout << endl;

	sort(toSort, out, u, v, n);
	
	cout << "out: ";
	for (int i = 0; i< n; i++)
		cout << out.get_item(i) << ' ';
	cout << endl;

	return 0;
}
