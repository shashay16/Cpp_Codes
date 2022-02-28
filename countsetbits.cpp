#include <iostream>

int main()
{
    int n;
    std::cout << "Enter integer: " << std::endl;
    std::cin >> n;
    int temp = n;
    int count = 0;
    while(temp>0) {
        if(temp&1)
            count++;
        temp = temp>>1;
    }
    std::cout << "Number of set bits in " << n << " is: "; 
    std::cout << count << std::endl;
    return 0;
}