#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int cube[10];

inline void getcube(int* arr)
{
    for (int i = 0 ; i < 10 ; i++) {
        arr[i] = i * i * i;
    }
}

void getArmstrongNumbers()
{
    for (int i = 0 ; i < 1000 ; i++) {
        int chk = 0, cur = i;
        while (cur) {
            chk += cube[cur % 10];
            cur /= 10;
        }
        if (chk == i)
            cout << i << endl;
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    getcube(cube);
    cout << "Get all armstrong numbers of 3" << endl;
    getArmstrongNumbers();

    return 0;
}