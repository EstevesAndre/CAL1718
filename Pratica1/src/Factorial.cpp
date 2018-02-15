/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
	if(n == 0 || n == 1) return 1;
	else{
		return factorialRecurs(n-1) * n;
	}
}

int factorialDinam(int n)
{
	int val = 1;
	if(n > 1)
	{
		for(int i = 2; i <= n; i++)
			val*=i;
	}
	return val;
}
