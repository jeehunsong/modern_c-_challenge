#include <iostream>
#include <vector>
#include <cstdlib>

#define endl '\n'

using namespace std;

long long GCD(long long x, long long y)
{
    if (y == 0) return x;
    return GCD(y, x % y);
}

long long LCM(long long x, long long y)
{
    return x * y / GCD(x, y);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int lcm = atoi(argv[1]);
    for (int i = 2 ; i < argc ; i++) {
        lcm = LCM(lcm, atoi(argv[i]));
    }
    cout << lcm << endl;

    return 0;
}