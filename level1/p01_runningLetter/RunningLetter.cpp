#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
using namespace std;
const int L = 0, R = 118;
int main()
{
	int step = 0, add = 1;
	while (1)
	{
		step += add;
		if (step == L || step == R)
		{
			step = -step;
		}
		system("cls");

		for (int i = 1; i <= step; ++i)
		{
			putchar(' ');
		}
		printf("run");
	}

	return 0;
}