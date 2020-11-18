#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int main ()
{
	char str[100], twoD[10][30];
	int i = 0, j = 0, k = 0, l = 0;
	cout<<"Enter the string\n";
	gets (str);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			twoD[k][j] = '\0';
			k ++;
			j = 0;
		}
		else
		{
			twoD[k][j] = str[i];
			j ++;
		}
	}
	twoD[k][j] = '\0';
	j = 0;
	for (i = 0; i < k; i++)
	{
		int present = 0;
		for (l = 1; l < k + 1; l++)
		{
			if (twoD[l][j] == '\0' || l == i)
			{
				continue;
			}
			if (strcmp (twoD[i], twoD[l]) == 0) {
				twoD[l][j] = '\0';
				present = present + 1;
			}
		}
	}
	j = 0;
	for (i = 0; i < k + 1; i++)
	{
		if (twoD[i][j] == '\0')
			continue;
		else
			cout<<twoD[i]<<' ';
	}
	cout<<"\n";
	return 0;
}
