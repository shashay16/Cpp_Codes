#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
        int i = 0;
        int maxJump = -1;
        int n = nums.size();
        if(n == 1) {
            return true;
        }
        if(nums[0] == 0) {
            return false;
        }
        while(i < n) {
            maxJump = nums[i];
            cout << "ggg" << maxJump << endl;
            if(maxJump >= n-1-i) {
                cout << maxJump;
                return true;
            }
            int j;
            int jump = -1;
            int idx;
            for(j=i+1; j<=i+maxJump; j++) {
                if(j<n && jump <= nums[j]) {
                    jump = nums[j];
                    idx = j;
                }
            }
            if(jump > n-1) {
                cout << "abc";
                return true;
            }
            maxJump = max(maxJump, nums[jump] + idx);
            if(nums[maxJump] == 0 && maxJump < n-1) {
                cout << "afgh";
                return false;
            }
            i = maxJump;
            //cout << i << endl;
        }
        cout << "bbb";
        return true;
    }


int main()
{
    vector<int> v {1,0,2};
    cout << canJump(v) << endl; 
    return 0;
}



