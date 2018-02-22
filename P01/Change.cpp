/*
 * Change.cpp
 */

#include "Change.h"

string calcChange(int m, int numCoins, int *coinValues)
{
	if(m == 0 || numCoins == 0)
		return "";

	//check if it is possible
	if (minCoins(numCoins-1, m, coinValues) == 0) { // if not possible
		return "-";
	}

	int numCoin = minCoins(numCoins - 1, m, coinValues);

	string output = "";

	for (unsigned int i = 0; i < numCoin; i++) 
	{
		int coin = lastCoin(numCoins - 1, m, coinValues);
		output += to_string(coin);
		output += ";";
		m -= coin;
	}
	return output;
}

int minCoins(int i, int k, int *coinValues) 
{
	if (k == 0) return 0;

	if (k < 0) return -1;

	else if (i == 0 || (coinValues[i] <= k && minCoins(i, k - coinValues[i], coinValues) < minCoins(i - 1, k, coinValues)))
		return 1 + minCoins(i, k - coinValues[i], coinValues);
	else
		return minCoins(i - 1, k, coinValues);
}

int lastCoin(int i, int k, int *coinValues)
{
	if (k == 0 || i == -1) return 0;

	if (coinValues[i] <= k && ( i == 0 || (1 + minCoins(i, k - coinValues[i], coinValues) < minCoins(i - 1, k, coinValues))))
		return coinValues[i];
	else
		return lastCoin(i - 1, k, coinValues);

}