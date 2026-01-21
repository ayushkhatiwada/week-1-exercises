#include <iostream>
#include <string>

void greeting(const std::string& s) {
    std::cout << s << std::endl;
}

int main() {
    std::string s = "Hello";
    greeting(s);

    return 0;
}
