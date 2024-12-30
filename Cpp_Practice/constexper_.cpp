#include <iostream>
using namespace std;

constexpr int result(int val) {
    return val*2;
}

int main() {
    int a = result(6);
    constexpr std::string s = "hello";
    static_assert(a == 12, "error");
    return 0;
}