#include "./../lc.h"

int solution(vector<int> &nums, int val) {
    int n = nums.size();
    int len = 0;
    for(int i = 0; i < n; ++i) {
        if(nums[i] == val)
            continue;
        nums[len++] = nums[i];
    }
    return len;
}

int main(int argc, char **argv) {
    vector<int> nums = {3,2,2,3};
    int res1 = solution(nums, 3);
    std::cout << "done.";
    return 0;
}