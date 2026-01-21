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

// Overload << operator so it can print vectors
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ", ";
    }
    os << ']';
    return os;
}

std::vector<int> create_fibonacci_vector(const int n) {
    if (n <= 0) throw std::invalid_argument("n must be a positive integer");
    if (n == 1) return std::vector<int> {0};
    if (n == 2) return std::vector<int> {0, 1};
    
    std::vector<int> fibonacci_vector;
    fibonacci_vector.reserve(n);
    fibonacci_vector.push_back(0);
    fibonacci_vector.push_back(1);

    for (int i = 2; i < n; i++) {
        int next_element = fibonacci_vector[i - 1] + fibonacci_vector[i - 2];
        fibonacci_vector.push_back(next_element);
    }
    return fibonacci_vector;
}


int main() {
    std::cout << create_fibonacci_vector(5) << std::endl;

    return 0;
}
