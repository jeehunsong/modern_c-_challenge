#include <iostream>
#include <sstream>
#include <string>

class IPv4 {
public:
    IPv4() {}
    IPv4(const std::string& str);
    friend std::istream& operator>>(std::istream& is, IPv4 &ip);
    friend std::ostream& operator<<(std::ostream& os, IPv4 &ip);
private:
    short address[4] = {-1, -1, -1, -1};
};

IPv4::IPv4(const std::string& str) {
    short inputAddr[4];
    std::istringstream iss(str);
    std::string token;
    for (int i = 0 ; i < 4 ; i++) {
        getline(iss, token, '.');

        std::string::size_type chkIdx;
        try {
            inputAddr[i] = std::stoi(token, &chkIdx);
            //std::cout << i << ": " << inputAddr[i] << " " << chkIdx << std::endl;
            if (chkIdx != token.size() || inputAddr[i] < 0 || inputAddr[i] > 255)
                // token is not number only
                // OR ip address is out of range
                return;
        }
        catch (...) {
            return;
        }
    }

    for (int i = 0 ; i < 4 ; i++)
        address[i] = inputAddr[i];
}

std::istream& operator>>(std::istream& is, IPv4 &ip) {
    std::string inputStr;
    is >> inputStr;
    ip = IPv4(inputStr);
    return is;
/*
    std::string inputStr;
    short inputAddr[4];

    is >> inputStr;
    //std::cout << "Input is " << inputStr << std::endl;
    std::istringstream iss(inputStr);
    std::string token;
    for (int i = 0 ; i < 4 ; i++) {
        getline(iss, token, '.');

        std::string::size_type chkIdx;
        inputAddr[i] = std::stoi(token, &chkIdx);
        //std::cout << i << ": " << inputAddr[i] << " " << chkIdx << std::endl;
        if (chkIdx != token.size() || inputAddr[i] < 0 || inputAddr[i] > 255)
            // token is not number only
            // OR ip address is out of range
            return is;
    }

    for (int i = 0 ; i < 4 ; i++)
        ip.address[i] = inputAddr[i];

    return is;
*/
}

std::ostream& operator<<(std::ostream& os, IPv4 &ip) {
    if (ip.address[0] != -1)
        os << ip.address[0] << "." << ip.address[1] << "." << ip.address[2] << "." << ip.address[3];
    return os;
}

int main() {
    IPv4 test;
    std::cout << "Input your IP Address (xxx.xxx.xxx.xxx): ";
    std::cin >> test;

    std::cout << std::endl;

    std::cout << "IP Output is " << test << std::endl;

    return 0;
}