#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void ShellSort(int a[], int n)
{
	for(int dk = n/2; dk >= 1; dk/=2)
	{
		for(int i = dk+1; i <= n; ++i)
		{
			if(a[i] < a[i-dk])
			{
				a[0] = a[i];
				int j;
				for(j = i-dk; j>0&&a[0]<a[j]; j-=dk)
				{
					a[j+dk] = a[j];
				}
				a[j+dk] = a[0];
			}
		
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
	
	ShellSort(a, sizeof(a)/sizeof(int)-1);
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	return 0;
}