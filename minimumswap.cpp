//Minimum swaps required to swap an Array!

#include <iostream>
#include <vector>
#include <algorithm>

int minSwaps(std::vector<int> &v) {
    int n = v.size();
    std::vector<std::pair<int,int>> vp(n);

    for(int i = 0; i<n; i++)
        vp[i] = {v[i],i};

    sort(vp.begin(), vp.end());

    int count = 0;
    for(int i = 0; i<n; i++) {
        if(vp[i].second == i)
            continue;
        else {
            count++;
            swap(vp[i],vp[vp[i].second]);
            i--;
        }
    }
    return count;
}

int main()
{
    int n;
    std::cout << "Enter number of integers: " << std::endl;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i =0; i<n; i++)
        std::cin >> v[i];

    int result = minSwaps(v);
    std::cout << "Minimum required swaps are: " << result << std::endl;
    return 0;
}