#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

/*
    1. Primitive type should have two arguments, not one argument
    2. Enable user defined binary comparison function
*/

template <typename T>
T getMinval(T x) {
    return x;
}

template <typename T, typename... Args>
T getMinval(T x, T y, Args... args) {
    return x > y ? getMinval(y, args...) : getMinval(x, args...);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    cout << getMinval(1) << endl;
    cout << getMinval(1, 2) << endl;
    cout << getMinval(5, 2, 3, 7, 6) << endl;

    return 0;
}