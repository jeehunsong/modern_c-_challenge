#include <iostream>
#include <utility>

#define endl '\n'

using namespace std;

/*
    1. Get template argument class, size, size
        - Constant size
    2. Use operator(), not []
        because () can get multiple arguments
    3. std::array vs std::vector
        Only std::vector can be constructed from std::initializer_list
        Move is implemented with std::initialize_list automatically
    4. std::vector<std::vector T>(C, std::vector(R)) vs std::vector<T>(C * R)
        Latter has a smaller memory footprint
*/

template <typename T>
class TwoDimArray {
public:
	TwoDimArray(unsigned int x = 0, unsigned int y = 0): sizex(x), sizey(y), pData(nullptr) {
	    if (isSizeValid(sizex, sizey)) {
            pData = new T[sizex * sizey];
            if (pData == nullptr) {
                sizex = 0;
                sizey = 0;
            }
        } else {
            sizex = 0;
            sizey = 0;
        }
	}

    TwoDimArray(unsigned int x, unsigned int y, const T& init): sizex(x), sizey(y), pData(nullptr) {
        if (isSizeValid(sizex, sizey)) {
            pData = new T[sizex * sizey];
            if (pData != nullptr) {
                for (int i = 0 ; i < sizex * sizey ; i++) {
                    pData[i] = init;
                }
            } else if (pData == nullptr) {
                sizex = 0;
                sizey = 0;
            }
        } else {
            sizex = 0;
            sizey = 0;
        }
    }

    // Copy Constructor
    TwoDimArray(const TwoDimArray& arr): sizex(arr.sizex), sizey(arr.sizey) {
        if (isSizeValid(sizex, sizey)) {
            pData = new T[sizex * sizey];
            if (pData != nullptr) {
                for (int i = 0 ; i < sizex * sizey ; i++) {
                    pData[i] = (arr.pData)[i];
                }
            }
        }
    }

    T& operator=(const TwoDimArray& arr) {
        delete[] pData;
        sizex = arr.sizex;
        sizey = arr.sizey;
        pData = nullptr;

        if (isSizeValid(sizex, sizey)) {
            pData = new T[sizex * sizey];
            if (pData != nullptr) {
                for (int i = 0 ; i < sizex * sizey ; i++) {
                    pData[i] = (arr.pData)[i];
                }
            }
        }
    }

    ~TwoDimArray() {
        if (pData != nullptr) {
            cout << "delete pData" << endl;
            delete[] pData;
        }
    }

    T& at(int x, int y) {
        if (x >= sizex || y >= sizey)
            throw out_of_range("Out of range occurs"s);
        return pData[sizex * x + y];
    }

    T* data() {
        return pData;
    }

    pair<int, int> size() {
        return make_pair(sizex, sizey);
    }

    void fill(const T& dataToFill) {
        for (int i = 0 ; i < sizex * sizey ; i++) {
            pData[i] = dataToFill;
        }
    }

    void swap() {
        TwoDimArray<T> temp = *this;

        sizex = temp.sizey;
        sizey = temp.sizex;

        for (int x = 0 ; x < sizex ; x++) {
            for (int y = 0 ; y < sizey ; y++) {
                this->at(x, y) = temp.at(y, x);
            }
        }
    }

    // TODO: move

private:
	int sizex, sizey;
	T* pData;

    bool isSizeValid(int x, int y) { return x > 0 && y > 0; }
};

int main(int argc, char** argv)
{
	TwoDimArray<int> test(3, 2, 1);
    
    try {
        cout << "test.at(2, 1) " << test.at(2, 1) << endl;
        cout << "test.at(3, 2) " << test.at(3, 2) << endl;  // out_of_range
    } catch (...) {
        cout << "Out of range occurs" << endl;
    }
    cout << "Address: " << test.data() << endl;
    cout << "Capacity: " << test.size().first << ", " << test.size().second << endl;
    test.fill(3);
    cout << "After fill data with 3, test.at(2, 1) " << test.at(2, 1) << endl;
    test.swap();
    cout << "Capacity after swap: " << test.size().first << ", " << test.size().second << endl;

    return 0;
}
