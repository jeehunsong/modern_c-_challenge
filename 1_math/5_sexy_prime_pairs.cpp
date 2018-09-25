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
    for (int i = 3 ; i + 2 < isPrime.size() ; i += 2) {
        if (isPrime[i] && isPrime[i + 2])
            cout << "(" << i << ", " << (i + 2) << ")" << endl;
    }
    return -1;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int x;

    cout << "Press the limit to get prime pairs" << endl;
    cin >> x;
    solve(x);

    return 0;
}