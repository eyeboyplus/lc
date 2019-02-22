#include "./../lc.h"

int helper(vector<int> &nums, int l, int r) {
    int prev = 0, cur = 0;
    for(int i = l; i <= r; i++) {
        int tmp = max(prev + nums[i], cur);
        prev = cur;
        cur = tmp;
    }
    return cur;
}

int solution(vector<int> &nums) {
    int n = nums.size();
    if(n < 2) return n ? nums[0] : 0;
    return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}