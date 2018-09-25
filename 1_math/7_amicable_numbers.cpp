#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int upperbound = 1'000'000;

void getAmicableNumbers(int input)
{
    if (input <= 0) return;

    vector<int> sumOfFactors(input + 1, 1);
    for (int i = 2 ; i < sumOfFactors.size() ; i++) {
        for (int j = 2 ; i * j < sumOfFactors.size() ; j++) {
            sumOfFactors[i * j] += i;
        }
        if (sumOfFactors[i] < i && sumOfFactors[sumOfFactors[i]] == i)
            cout << "(" << sumOfFactors[i] << ", " << i << ")" << endl;
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int input;

    cout << "All pairs under " << upperbound << endl;
    getAmicableNumbers(upperbound);

    return 0;
}