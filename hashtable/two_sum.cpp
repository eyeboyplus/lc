#include "./../lc.h"

vector<int> solution(vector<int> nums, int target) {
    unordered_map<int, int> map;
    int n = nums.size();
    for(int i = 0; i < n; ++i) {   
        int diff = target - nums[i];
        if(map.find(diff) != map.end())
            return {i, map[diff]};

        if(map.find(nums[i]) == map.end())
            map[nums[i]] = i;
    }
    return {};
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}