#include "./../lc.h"

int solution(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(nums[mid] == target) {                   // 找到目标元素
            return mid;
        } else if(nums[mid] < nums[right]) {        // nums[mid : right]升序
            if(target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        } else {                                    // nums[left : mid]升序
            if(target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}