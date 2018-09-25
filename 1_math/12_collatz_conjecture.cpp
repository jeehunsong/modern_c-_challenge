#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int upperbound = 1'000'000;

inline unsigned int getNextCollatzSequence(unsigned int x)
{
    return (x % 2 == 0) ? x / 2 : 3 * x + 1;
}

vector<int> cache;

int getLength(int start) {
    if (start > upperbound) return 0;
    if (cache[start] != -1) return cache[start];
    
    int& ret = cache[start];
    ret = getLength(getNextCollatzSequence(start)) + 1;
    return ret;
}

unsigned int getStartOfLongestCollatzSeuquence() {
    int maxLen = 1, ret = 1;
    cache[1] = 1;

    for (int i = 2 ; i <= upperbound ; i++) {
        int len = getLength(i);
        if (len > maxLen) {
            maxLen = len;
            ret = i;
        }
    }
    return ret;
}

void solve()
{
    cache = vector<int>(upperbound + 1, -1);
    unsigned int start = getStartOfLongestCollatzSeuquence();
    while (start != 1) {
        cout << start << " ";
        start = getNextCollatzSequence(start);
    }
    cout << start << endl;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    cout << "The largest Collatz sequence up to " << upperbound << endl;
    solve();

    return 0;
}