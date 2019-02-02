#include "./../lc.h"

vector<int> solution(vector<int> &nums, int target) {
    int n = nums.size() - 1;
    int left = 0, right = n;
    vector<int> ret(2, -1);
    // 搜索左边界
    while(left < right) {
        int mid = (left + right) / 2;
        if(target > nums[mid])
            left = mid + 1;
        else
            right = mid;
    }
    if(nums[left] != target)
        return ret;
    else
        ret[0] = left;
    // 搜索右边界
    right = n - 1;
    while(left < right) {
        int mid = (left + right) / 2 + 1;
        if(target < nums[mid])
            right = mid - 1;
        else
            left = mid;
    }
    ret[1] = right;
    return ret;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}