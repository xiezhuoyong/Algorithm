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

void SelectSort(int a[], int n)
{
	for(int i = 0; i < n-1; ++i)
	{
		int min = i;
		for(int j = i+1; j < n; ++j)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			swap(a[i], a[min]);
		}
	}
}

int main(int argc, const char* argv[])
{
	int a[] = {1,4,7,8,5,2,9,11,10,100,74,37,85,6,25,36,75,325,146};
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	SelectSort(a, sizeof(a)/sizeof(int));
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	return 0;
}