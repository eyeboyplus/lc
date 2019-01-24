#include "./../lc.h"

// hash方法
vector<int> solution_1(vector<int> &nums, int target) {
    unordered_map<int, int> um;
    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(um.find(target - nums[i]) != um.end())
            return {i, um[target - nums[i]]};
        else
            um[nums[i]] = i;
    }
    return {};
}

int main(int argc, char **argv) {
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> res1 = solution_1(nums1, 9);
    std::cout << "done.";
    return 0;
}