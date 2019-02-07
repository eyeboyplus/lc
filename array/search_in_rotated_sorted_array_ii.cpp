#include "./../lc.h"

bool solution(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(nums[mid] == target) return true;
        
        if(nums[left] < nums[mid]) {
            if(target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else if(nums[left] > nums[mid]) {
            if(target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        } else {        // left,right下标元素相等时，无法判断递增区间，left向前移动
            left ++;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}