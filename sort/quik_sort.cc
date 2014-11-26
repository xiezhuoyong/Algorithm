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

int Partition1(int a[], int low, int high)
{
	int pivot = a[low];
	while(low < high)
	{
		while(low < high && a[high] >= pivot)
			--high;
		a[low] = a[high];
		while(low < high && a[low] <= pivot)
			++low;
		a[high] = a[low];
	}
	
	a[low] = pivot;
	return low;
}

int Partition2(int a[], int p, int r)
{
	int pivot = a[r];
	int i = p-1;
	for(int j = p; j < r; ++j)
	{
		if(a[j] <= pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;
}

void QuikSort(int a[], int low, int high)
{
	if(low < high)
	{
		int pivotpos = Partition2(a, low, high);
		QuikSort(a, low, pivotpos-1);
		QuikSort(a, pivotpos+1, high);
	}
}

int main(int argc, const char* argv[])
{
	int a[] = {1,4,7,8,5,2,9,11,10,100,74,37,85,6,25,36,75,325,146};
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	int low = 0, high = sizeof(a)/sizeof(int)-1;
	QuikSort(a, low, high);
	
	print(a, sizeof(a)/sizeof(int));
	cout << endl;
	
	return 0;
}