#include "./../lc.h"

int solution(vector<int> &nums) {
    int len = 0, n = nums.size();
    if(n == 0)
        return 0;
    for(int i = 1; i < n; ++i) {
        if(nums[len] != nums[i])
            nums[len++] = nums[i];
    }
    return len + 1;
}

int main(int argc, char **argv) {
    vector<int> nums1 = {1,1,2};
    int res1 = solution(nums1);
    vector<int> nums2 = {0};
    int res2 = solution(nums2);
    std::cout << "done.";
    return 0;
}