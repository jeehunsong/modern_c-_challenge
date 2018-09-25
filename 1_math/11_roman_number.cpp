#include <iostream>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

const string ones[] = {"I"s, "X"s, "C"s, "M"s, "(X)"s};
const string fives[] = {"V"s, "L"s, "D"s, "V"s};

string getThisRomanNum(int x, string one, string five, string ten)
{
    if (x == 4)
        return (one + five);
    else if (x == 9 && !ten.empty())
        return (one + ten);
    string ret;

    if (x >= 5) {
        x -= 5;
        ret += five;
    }
    while (x > 0) {
        x--;
        ret += one;
    }
    return ret;
}

string numToRoman(int num)
{
    if (num >= 10000) return "NOT POSSIBLE"s;

    string ret;
    for (int i = 1000, j = 3 ; i > 0 && j >= 0 ; ) {
        //cout << "i: " << i << endl;
        ret += getThisRomanNum(num / i, ones[j], fives[j], ones[j + 1]);
        //cout << "ret: " << ret << endl;
        num %= i;
        i /= 10;
        j--;
    }
    return ret;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int num;
    cout << "Enter number to conver to roman number" << endl;
    cin >> num;
    cout << numToRoman(num) << endl;

    return 0;
}