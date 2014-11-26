#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void print(int a[], int lengh)
{
	for(int i = 0; i < lengh; ++i)
		cout << a[i] << " ";
}

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void AdjustDown(int a[], int k, int len)
{
	a[0] = a[k];
	for(int i = 2*k; i <= len; i *=2)
	{
		if(i < len && a[i] < a[i+1])
			i++;
		if(a[0] >= a[i])
			break;
		else
		{
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = a[0];
}

void BuildMaxHeap(int a[], int len)
{
	for(int i = len/2; i > 0; i--)
	{
		AdjustDown(a, i, len);
	}
}

void HeapSort(int a[], int len)
{
	BuildMaxHeap(a, len);
	for(int i = len; i > 1; i--)
	{
		swap(a[1], a[i]);
		AdjustDown(a, 1, i-1);
	}
}


int main(int argc, const char* argv[])
{
	int a[] = {1,4,7,8,5,2,9,11,10,100,74,37,85,6,25,36,75,325,146};
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	HeapSort(a, sizeof(a)/sizeof(int)-1);
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	return 0;
}

