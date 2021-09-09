// Time (milliseconds).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<time.h>

int _tmain(int argc, _TCHAR* argv[])
{
	clock_t start, stop;
	int i;
	start = clock();
	for (i = 0; i<2000; i++)
	{
	printf("%d", (i * 1) + (1 ^ 4));
	}
	printf("\n\n");
	stop = clock();

	(double)(stop - start) / CLOCKS_PER_SEC;

	printf("%6.3f", start);
	printf("\n\n%6.3f", stop);


	return 0;
}

