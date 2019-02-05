#include "./../lc.h"

bool solution(vector<int> &nums) {
    int index = 0, n = nums.size();
    // farest 表示所能达到的最远下标
    // index 逐个遍历数组的下标
    // 所有元素都是非负，不存在后退情况，所以index <= farest，
    // 只有在当前元素为0时,下一次迭代会出现index > farest的情况，此时退出遍历
    for(int farest = 0; index < n && index <= farest; ++index) {
        farest = max(index + nums[index], farest); 
    }
    return index == n;
}

int main(int argc, char **argv) {
    vector<int> nums = {2,3,1,1,4};
    bool res = solution(nums);
    std::cout << "done.";
    return 0;
}