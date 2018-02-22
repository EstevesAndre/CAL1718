#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

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

		for (unsigned int j = i, n = 0; j < size; j++, n++)
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

int main()
{
	fstream file;
	file.open("times.txt");

	if (file.fail())
	{
		cout << "Inexistent file\n";
		return 1;
	}
	else
	{
		int values[5000];

		int numbers[] = { 10,20,50,100,200,500 };

		for (unsigned int i = 0; i < 6; i++)
		{
			file << "n = " << numbers[i] << endl << endl;
			for (unsigned int j = 0; j < 1000; j++)
			{
				for (unsigned int k = 0; k < numbers[i]; k++)
				{
					values[k] = 1 + rand() % (10 * numbers[i]);
				}

				auto start = std::chrono::high_resolution_clock::now();
				calcSum(values, numbers[i]);
				auto finish = std::chrono::high_resolution_clock::now();
				auto mili = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
				file << mili << endl;
			}
		}
	}
}