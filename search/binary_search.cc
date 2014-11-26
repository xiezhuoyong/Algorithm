#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int Binary_search(int a[], int len, int key)
{
	int low = 0;
	int high = len - 1;
	int mid;
	
	while(low <= high)
	{
		mid = (low+high)/2;
		if(a[mid] == key)
			return mid;
		else if(a[mid] < key)
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return -1;
}

int main(int argc, const char *argv[])
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	
	cout << Binary_search(a, sizeof(a)/sizeof(a[0]), 8) << endl;

	return 0;
}