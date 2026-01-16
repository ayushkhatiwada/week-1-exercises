#include <iostream>
#include <cstdint>
#include <stdexcept>

uint64_t factorial0(int x) {
    if (x < 0) throw std::invalid_argument("factorial is undefined for negative integers");

    if (x <= 1) return 1;
    return uint64_t(x) * factorial0(x - 1);
}

uint64_t factorial1(int x) {
    if (x < 0) throw std::invalid_argument("factorial is undefined for negative integers");

    uint64_t result = 1;
    while (x >= 2) {
        result *= x;
        x--;
    }
    return result;
}

uint64_t factorial2(int x) {
    if (x < 0) throw std::invalid_argument("factorial is undefined for negative integers");

    uint64_t result = 1;
    for (uint64_t i = 2; i <= x; i++) {
        result *= i;
    }
    return result;
}

int main() {
    std::cout << factorial0(13) << std::endl;
    std::cout << factorial1(13) << std::endl;
    std::cout << factorial2(13) << std::endl;

    return 0;
}
