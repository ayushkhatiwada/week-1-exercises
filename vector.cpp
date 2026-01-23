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


template<typename T, typename U>
std::vector<T> scale_vector(const std::vector<T>& vector, const U& scalar) {
    std::vector<T> output_vector;
    output_vector.reserve(vector.size());
    
    for (const T& element : vector) {
        output_vector.push_back(scalar * element);
    }
    return output_vector;
}

template <typename T, typename U>
auto scale_vector2(const std::vector<T>& v, const U& scalar)
    -> std::vector<decltype(T{} * scalar)>
{
    using R = decltype(T{} * scalar);
    std::vector<R> result;
    result.reserve(v.size());

    for (const T& element : v)
        result.push_back(scalar * element);

    return result;
}


// Vectors of the same type
template<typename T>
std::vector<T> add_vectors(const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size()) throw std::invalid_argument("Vectors must be of the same size");

    std::vector<T> result;
    result.reserve(v1.size());

    for (std::size_t i = 0; i < v1.size(); i++) {
        result.push_back(v1[i] + v2[i]);
    }
    return result;
}

template<typename T, typename U>
auto add_vectors2(const std::vector<T>& v1, const std::vector<U>& v2) 
    -> std::vector<decltype(T{} + U{})>
{
    if (v1.size() != v2.size()) throw std::invalid_argument("Vectors must be of the same size");

    using R = decltype(T{} + U{});
    std::vector<R> result(v1.size());

    for (std::size_t i = 0; i < v1.size(); i++) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}



int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<double> v2 = {4, 5, 6};
    std::cout << add_vectors2(v1, v2) << std::endl;

    return 0;
}
