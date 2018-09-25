#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

void chkUpdate(int& x, int factor, vector<int>& ret)
{
    if (x % factor == 0) {
        ret.push_back(factor);
        while (x % factor == 0)
            x /= factor;
    }
}

vector<int> primeFactors(int input)
{
    vector<int> ret;

    chkUpdate(input, 2, ret);
    for (int i = 3 ; i <= input ; i += 2) {
        chkUpdate(input, i, ret);
    }

    return ret;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int input;
    cout << "Enter the number to find prime factors" << endl;
    cin >> input;
    vector<int> output = primeFactors(input);   
    for (auto it: output)
        cout << it << endl;

    return 0;
}