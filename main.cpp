#include <iostream>

std::string get_address_part(std::string str, int n) {
    int point = 0;
    std::string oktet = "";
    for (int i = 0; i < str.length() && point <= n; i++) {
        if (str[i] == '.') point++;
        else if (point == n) oktet += str[i];
    }
    return oktet;
}

bool checking_IP_oktet (std::string str) {
    if (str.empty()) return false;
    int sum = 0;
    for (int i = 0; i < str.length (); i++) {
        if (!(str[i] >= '0' && str[i] <= '9') || sum == 0 && i > 0) return false;
        sum *= 10;
        sum += (str[i] - '0') % 10;
    }
    if (sum > 255) {
        return false;
    } else return true;
}

bool checking_IP_address (std::string str) {
    if (str [str.length() - 1] == '.') return false;
    int i = 0;
    for (; checking_IP_oktet(get_address_part(str, i)); i++);
    if (i == 4) return true;
    else return false;
}

int main() {
    std::cout << "Enter the IP-address: " << std::endl;
    std::string IP_address;
    std::cin >> IP_address;

    checking_IP_address(IP_address) ? std::cout << "Valid. \n" : std::cout << "Invalid. \n";

    return 0;
}
