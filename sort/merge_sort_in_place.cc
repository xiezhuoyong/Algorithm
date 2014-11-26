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

void reverse(int a[], int n)
{
	int i = 0, j = n-1;
	while(i < j)
	{
		swap(a[i], a[j]);
		i++;
		j--;
	}
}

void exchange(int a[], int n, int i)
{
	reverse(a, i);
	reverse(a+i, n-i);
	reverse(a, n);
}

void merge(int a[], int begin, int mid, int end)
{
	int i = begin;
	int j = mid;
	int k = end;
	
	while(i < j && j <=k)
	{
		int step = 0;
		while(i < j && a[i] <= a[j])
			++i;
		while(j <=k && a[j] <= a[i])
		{
			++j;
			++step;
		}
		exchange(a+i, j-i, j-i-step);
	}
}

void MergeSort(int a[], int low, int high)
{
	if(low < high)
	{
		int mid = (low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		merge(a, low, mid+1, high);
	}
}

int main(int argc, const char* argv[])
{
	int a[] = {1,4,7,8,5,2,9,11,10,100,74,37,85,6,25,36,75,325,146};
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	MergeSort(a, 0, sizeof(a)/sizeof(a[0])-1);
	//reverse(a, 10);
	//exchange(a, 10, 5);
	//merge(a, 0, 5, 9);
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	return 0;
}