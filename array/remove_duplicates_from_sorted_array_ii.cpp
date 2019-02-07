#include "./../lc.h"

int solution(vector<int> &nums) {
    int n = nums.size();
    if(n <= 2) return n;
    int cnt = 0, idx = 0;
    for(int i = 1; i < n; ++i) {
        if(nums[i] == nums[idx]) {
            if(++cnt > 1)
                continue;
            else
                nums[++idx] = nums[i];
        } else {
            cnt = 0;
            nums[++idx] = nums[i];
        }
    }
    return idx + 1;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}