#include <iostream>
using namespace std;

void f(int& i) {
    cout << "l value" << endl;
}

void f(const int& i) {
    cout << "const l value" << endl;
}

// void f(int&& i) {
//     cout << "r value" << endl;
// }


int main() {
    int i = 10;
    f(i);
    f(10);
    f(std::move(i));
    f(static_cast<int &&>(i));
    return 0;
}