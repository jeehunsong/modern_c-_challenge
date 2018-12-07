#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <iterator>

#define endl '\n'

using namespace std;

template <typename Container_t, typename T>
bool contains_any(Container_t c, T v)
{
    for (auto it = begin(c) ; it != end(c) ; it++)
        if (*it == v)
            return true;
    return false;
}

template <typename Container_t, typename T, typename... Args>
bool contains_any(Container_t c, T v, Args... args)
{
    if(contains_any(c, v) == true)
        return true;
    return contains_any(c, args...);
}

template <typename Container_t, typename T>
bool contains_all(Container_t c, T v)
{
    return contains_any(c, v);
}

template <typename Container_t, typename T, typename... Args>
bool contains_all(Container_t c, T v, Args... args)
{
    if(contains_any(c, v) == false)
        return false;
    return contains_all(c, args...);
}

template <typename Container_t, typename... Args>
bool contains_none(Container_t c, Args... args)
{
    return !contains_any(c, args...);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    vector<int> v{1, 2, 3, 4, 5, 6};
    cout << contains_any(v, 0, 3, 30) << endl;

    array<int, 6> a{ {1, 2, 3, 4, 5, 6} };
    cout << contains_all(a, 1, 3, 5, 6) << endl;

    list<int> l{ 1, 2, 3, 4, 5, 6 };
    cout << contains_none(l, 0, 7) << endl;

    return 0;
}