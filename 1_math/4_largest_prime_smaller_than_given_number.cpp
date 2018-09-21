#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int solve(int x)
{
    vector<bool> isPrime(x, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2 ; i * i <= x ; i++) {
        if (isPrime[i] == true) {
            for (int j = 2 ; i * j < isPrime.size() ; j++) {
                isPrime[i * j] = false;
            }
        }
    }
    for (int i = x - 1 ; i >= 0 ; i--) {
        if (isPrime[i] == true)
            return i;
    }
    return -1;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int x;

    cout << "Press the number to get the largest prime smaller than input" << endl;
    cin >> x;
    cout << solve(x) << endl;

    return 0;
}