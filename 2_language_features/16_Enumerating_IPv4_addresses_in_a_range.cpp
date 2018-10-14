#include <iostream>
#include <sstream>
#include <string>

class IPv4 {
public:
    IPv4() {}
    IPv4(const std::string& str);

    bool operator==(const IPv4& x) const {
        return x.address[0] == address[0] && x.address[1] == address[1] && x.address[2] == address[2] && x.address[3] == address[3];
    }

    bool operator<(const IPv4& x) const {
        for (int i = 0 ; i < 4 ; i++)
            if (address[i] < x.address[i]) return true;
            else if (address[i] > x.address[i]) return false;
        // ALL same
        return false;
    }

    bool operator<=(const IPv4& x) const {
        for (int i = 0 ; i < 4 ; i++)
            if (address[i] < x.address[i]) return true;
            else if (address[i] > x.address[i]) return false;
        // ALL same
        return true;
    }

    bool operator>(const IPv4& x) const {
        return x < *this;
    }

    bool operator>=(const IPv4& x) const {
        return x <= *this;
    }

    IPv4& operator++() {
        int i = 3;
        while (i >= 0) {
            if (address[i] < 255) {
                ++address[i];
                break;
            }
            address[i] = 0;
            --i;
        }
        return *this;
    }

    IPv4 operator++(int) {
        IPv4 temp = *this;
        ++*this;
        return temp;
    }

    bool isValid() {
        return address[0] != -1;
    }

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
}


std::ostream& operator<<(std::ostream& os, IPv4 &ip) {
    if (ip.address[0] != -1)
        os << ip.address[0] << "." << ip.address[1] << "." << ip.address[2] << "." << ip.address[3];
    return os;
}

void getIPList() {
    IPv4 from, to;
    std::cout << "Input IP address starts from(xxx.xxx.xxx.xxx): ";
    std::cin >> from;
    std::cout << "Input IP address ends (xxx.xxx.xxx.xxx): ";
    std::cin >> to;

    if (from.isValid() == false || to.isValid() == false || from > to)
        std::cout << "IP range is not valid" << std::endl;

    while (from <= to) {
        std::cout << from << std::endl;
        ++from;
    }
}

int main() {
    getIPList();

    return 0;
}