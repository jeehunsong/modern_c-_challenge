#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'

using namespace std;

const int precision = 5;

double leibniz(int n) {
    // 4 * ((-1)^n) / (2n + 1)
    if (n % 2 == 0) {
        return 4.0 / (static_cast<double>(2 * n) + 1);
    }
    return -4.0 / (static_cast<double>(2 * n) + 1);
}

double leibnizUpperbound(int n) {
    if (n == 0) return 4.0;
    return (-8.0) / ((4.0 * n - 1.0) * (4.0 * n + 1.0));
}

double leibnizLowerbound(int n) {
    // 8 / ((4n + 1)(4n + 3))
    return 8.0 / ((4.0 * n + 1.0) * (4.0 * n + 3.0));
}

double solve(int iprec) {
    double dprec = 1.0;
    for (int i = 1 ; i < iprec ; i++)
        dprec *= 10;

    int i = 0;
    double ub = leibnizUpperbound(i), lb = leibnizLowerbound(i);
    while ((floorf(ub * dprec) != floorf(lb * dprec))) {
        i++;
        ub += leibnizUpperbound(i);
        lb += leibnizLowerbound(i);
        //cout << i << " " << ub << " " << lb << endl;
    }
    return floorf(lb * dprec) / dprec;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    cout << "Compute pi with precision of " << precision << " decimal digits" << endl;
    cout << solve(precision) << endl;

    return 0;
}