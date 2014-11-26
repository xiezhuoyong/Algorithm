#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
using namespace std;

//暴力法
int ViolentKmp(const char *s, const char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);
	
	int i = 0;
	int j = 0;
	while(i < sLen && j < pLen)
	{
		if(s[i] == p[j])
		{
			i++;
			j++;
		}
		else 
		{
			i = i - j + 1;
			j = 0;
		}
	}
	
	if(j == pLen)
		return i - j;
	else 
		return -1;
}


int main(int argc, const char *argv[])
{
	char a[] = "abcdef";
	char b[] = "def";
	cout << ViolentKmp(a, b) << endl;
}