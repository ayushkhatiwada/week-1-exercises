#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T>
T get_max_item_in_vector(const std::vector<T>& v) {
    if (v.empty()) throw std::invalid_argument("vector is empty");

    return *std::max_element(v.begin(), v.end());

    T max = v[0];
    for (T item : v) {
        if (item > max) max = item;
    }

    return max;
}



int main() {
    std::vector<int> a = {-10, 2, 3, 10};
    std::cout << get_max_item_in_vector(a) << std::endl;

    return 0;
}

