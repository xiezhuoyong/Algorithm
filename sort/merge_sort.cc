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



void Merge(int a[], int low, int mid, int high, int b[])
{
	for(int k = low; k <= high; k++)
	{
		b[k] = a[k];
	}
	
	int i, j, k;
	for(i = low, j = mid+1, k = i; i <= mid && j <= high; k++)
	{
		if(b[i] < b[j])
		{
			a[k] = b[i++];
		}
		else
		{
			a[k] = b[j++];
		}
	}
	while(i <= mid)
		a[k++] = b[i++];
	while(j <= high)
		a[k++] = b[j++];
}

void MergeSort(int a[], int low, int high, int b[])
{
	if(low < high)
	{
		int mid = (low + high)/2;
		MergeSort(a, low, mid, b);
		MergeSort(a, mid+1, high, b);
		Merge(a, low, mid, high, b);
	}
}

int main(int argc, const char* argv[])
{
	int a[] = {1,4,7,8,5,2,9,11,10,100,74,37,85,6,25,36,75,325,146};
	int *b = (int *)malloc((sizeof(a)/sizeof(int)+1) * sizeof(int));
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	MergeSort(a, 0, sizeof(a)/sizeof(int)-1, b);
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	return 0;
}
