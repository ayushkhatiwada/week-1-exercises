#include <iostream>
#include <vector>


int main() {
    std::vector<int> v;
    v.reserve(100);
    std::cout << v[0] << std::endl;


    return 0;
}
