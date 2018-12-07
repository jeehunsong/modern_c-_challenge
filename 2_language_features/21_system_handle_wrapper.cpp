#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

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