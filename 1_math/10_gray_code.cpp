#include <iostream>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

const int nbits = 5;

vector<int> getGraycode(int n)
{
    vector<int> ret;

    for (int i = 0 ; i < (1 << n) ; i++) {
        ret.push_back(i ^ (i >> 1));
    }

    return ret;
}

string printBinary(int x, int bits)
{
    string ret;
    for (int i = bits - 1 ; i >= 0 ; i--) {
        if (x & (1 << i))
            ret += "1";
        else
            ret += "0";
    }
    return ret;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    cout << "Gray code for all 5-bit numbers" << endl;

    vector<int> gray5bit = getGraycode(nbits);

    for (auto x: gray5bit)
        cout << printBinary(x, nbits) << endl;

    return 0;
}