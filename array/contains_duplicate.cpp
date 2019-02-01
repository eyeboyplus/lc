#include "./../lc.h"

// hash
bool solution(vector<int> &nums) {
    unordered_set<int> hash;
    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(hash.find(nums[i]) != hash.end())
            return true;
        else
            hash.insert(nums[i]);
    }
    return false;
}

int main(int argc, char **argv) {
    vector<int> nums1 = {1, 2, 3, 1};
    int res1 = solution(nums1);
    vector<int> nums2 = {1, 2, 3, 4};
    int res2 = solution(nums2);
    std::cout << "done.";
    return 0;
}