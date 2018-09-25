#include <string>
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

bool isValidIsbn(const string& input) {
    int i = 10, s = 0;
    for (auto it = input.begin() ; it != input.end() ; it++) {
        if (*it >= '0' && *it <= '9') {
            s += (*it - '0') * i;
            --i;
            if (i < 0)
                break;
        }
    }
    return (i == 0) && (s % 11 == 0);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    string input;
    cout << "Input 10 digits to check valid ISBNs" << endl;
    cin >> input;
    if (isValidIsbn(input))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;

    return 0;
}