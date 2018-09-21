#include <iostream>

using namespace std;

inline long long getSumFromOne(long long x)
{
	return x * (x + 1) / 2;
}

inline long long solve(int x)
{
	return getSumFromOne(x / 3) * 3 + getSumFromOne(x / 5) * 5 - getSumFromOne(x / 15) * 15;
}

int main(int argc, char** argv)
{
	int input;
	cout << "Input the number to get the sum of all numbers lower than that number and divisible by either 3 or 5" << endl;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}
