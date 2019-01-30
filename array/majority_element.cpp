#include "./../lc.h"

// Moore voting algorithm
int solution(vector<int> &nums) {
    int n = nums.size(), majority, count = 0;
    for(int i = 0; i < n; ++i) {
        if(!count) {
            majority = nums[i];
            count = 1;
        } else {
            count += (majority == nums[i] ? 1 : -1);
        }
    }
    return majority;
}

int main(int argc, char **argv) {
    vector<int> nums1 = {3, 2, 3};
    int res1 = solution(nums1);
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    int res2 = solution(nums2);
    std::cout << "done.";
    return 0;
}