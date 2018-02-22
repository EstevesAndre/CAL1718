/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>

string calcSum(int* sequence, int size)
{
	string out = "";

	vector<int> vals;
	for (unsigned int i = 0; i < size; i++)
	{
		vals.push_back(0);
	}

	int sum = 0;

	for (unsigned int i = 0; i < size; i++)
	{
		int index = 0;
		int min_value = *(sequence + i) + vals.at(0);

		for (unsigned int j = i, n = 0; j < size; j++,n++)
		{
			vals.at(n) += *(sequence + j);

			if (vals.at(n) < min_value)
			{
				min_value = vals.at(n);
				index = n;
			}
		}
		out += to_string(min_value) + ',' + to_string(index) + ';';
	}
	return out;
}

