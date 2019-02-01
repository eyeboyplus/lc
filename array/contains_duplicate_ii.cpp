#include "./../lc.h"

bool solution(vector<int> &nums, int k) {
    unordered_set<int> hash;
    int n = nums.size();
    if(k < 0)
        return false;
    if(k > n - 1)
        k = n - 1;
    for(int i = 0; i < n; ++i) {
        if(i > k) hash.erase(nums[i - k - 1]);  // 超过窗口大小k时，每次都会删除最前面的元素
        if(hash.find(nums[i]) != hash.end())
            return true;
        hash.insert(nums[i]);
    }
    return false;
}

int main(int argc, char **argv) {
    vector<int> nums1 = {1, 2, 3, 1};
    bool res1 = solution(nums1, 3);
    vector<int> nums2 = {1, 0, 1, 1};
    bool res2 = solution(nums2, 1);
    std::cout << "done.";
    return 0;
}