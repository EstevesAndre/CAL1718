/*
 * Partioning.cpp
 */

#include "Partitioning.h"


int s_recursive(int n,int k)
{
	if (1 < k && k < n)
		return s_recursive(n - 1, k - 1) + k*s_recursive(n - 1, k);
	else if(k == 1 || n == k)
		return 1;
}

int s_dynamic(int n,int k)
{
	vector<int> vals;
	for (unsigned int i = 0; i <= k; i++)
	{
		if (i == 1)
			vals.push_back(1);
		else
			vals.push_back(0);
	}

	for (unsigned int i = 2; i <= n; i++)
	{
		for (unsigned int j = k; j > 1; j--)
		{
			vals[j] = j * vals[j] + vals[j - 1];
		}
	}
	return vals[k];
}


int b_recursive(int n)
{
	int val = 0;
	for (unsigned int i = 1; i <= n; i++)
	{
		val += s_recursive(n, i);
	}

	return val;
}

int b_dynamic(int n)
{
	int val = 0;
	for (unsigned int i = 1; i <= n; i++)
	{
		val += s_dynamic(n, i);
	}

	return val;
}


