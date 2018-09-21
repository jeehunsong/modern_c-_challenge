#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int getGcd(int x, int y)
{
    if (x == 0) return y;
    if (x < y) return getGcd(x, y - x); // Euclidean Algorithm
    return getGcd(y, x - y);
}

int getGcd2(int x, int y)
{
    // Euclidean Algorithm with while loop
    if (x == 0) return y;
    while (x != y)
        if (x < y) 
            y -= x;
        else
            x -= y;
    return x;
}

int getGcd3(int x, int y)
{
    // Euclidean Algorithm with modulo
    if (y == 0) return x;
    return getGcd3(y, x % y);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int x, y;

    cout << "Get two numbers to get the greatest common divisor" << endl;

    cin >> x >> y;
    cout << getGcd(x, y) << endl;

    return 0;
}