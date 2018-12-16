#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

/*
    1. System handles: reference to system resources
        written in C
        creating and releasing the handles is done through dedicated system functions
        function called when open, read from, and close a file
    2. Possible error by developers
        2-1. Forgot to close the handle before leaving the function
        2-2. A function that throws is called before the handle is properly closed without exception being caught, hence the cleanup code never executes
    3. Objective of system handle wrapper with respect to 2
        3-1. Destructor close the handle
        3-2. Move semantics
        3-3. Comparison operator
        3-4. swapping and resetting
    4. traits
    5. OS dependent solution 
*/

template <typename Handle_t>
class handleWrapper {
public:
    handleWrapper(Handle_t handle): handle(handle) {
        // acquisition
    }

    ~handleWrapper() {
        // release
    }

    

private:
    Handle_t handle;
};

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    

    return 0;
}