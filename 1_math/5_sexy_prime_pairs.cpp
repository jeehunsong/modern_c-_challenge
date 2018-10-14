#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int differ = 6;

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
    for (int i = 3 ; i + differ < isPrime.size() ; i += 2) {
        if (isPrime[i] && isPrime[i + differ])
            cout << "(" << i << ", " << (i + differ) << ")" << endl;
    }
    return -1;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int x;

    cout << "Press the limit to get Sexy prime pairs" << endl;
    cin >> x;
    solve(x);

    return 0;
}