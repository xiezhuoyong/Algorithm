#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void InsertSort(int a[], int n)
{
	int i, j;
	for(i=2; i<=n; ++i)
	{
		if(a[i] < a[i-1])
		{
			a[0] = a[i];
			for(j = i-1; a[0] < a[j]; --j)
			{
				a[j+1] = a[j];
			}
			a[j+1] = a[0];
		}
	}
}

void print(int a[], int lengh)
{
	for(int i = 1; i < lengh; ++i)
		cout << a[i] << " ";
}

int main(int argc, const char* argv[])
{
	int a[] = {1,4,7,8,5,2,9,11,10,100,74,37,85,6,25,36,75,325,146};
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	InsertSort(a, sizeof(a)/sizeof(int)-1);
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	return 0;
}