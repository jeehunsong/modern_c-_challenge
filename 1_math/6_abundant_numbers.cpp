#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

void getAllAbundantNumbers(int input)
{
    if (input <= 0) return;

    vector<int> sumOfFactors(input + 1, 1);
    for (int i = 2 ; i < sumOfFactors.size() ; i++) {
        for (int j = 2 ; i * j < sumOfFactors.size() ; j++) {
            sumOfFactors[i * j] += i;
        }
        if (sumOfFactors[i] > i)
            cout << i << ": " << sumOfFactors[i] << endl;
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int input;

    cout << "Enter the upperbound to get all abundant numbers" << endl;
    cin >> input;
    getAllAbundantNumbers(input);

    return 0;
}