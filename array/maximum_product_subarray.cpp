#include "./../lc.h"

int solution(vector<int> &nums) {
    int result = nums[0];
    int n = nums.size();

    // imax、imin分别保存到目前为止的最大值和最小值
    for(int i = 1, imax = nums[0], imin = nums[0]; i < n; ++i) {
        // 如果当前元素小于0，则imax将成为最小值，imin将成为最大值，所以交换
        if(nums[i] < 0)
            swap(imax, imin);
        imax = max(nums[i], imax * nums[i]);
        imin = min(nums[i], imin * nums[i]);
        result = max(imax, result);
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}