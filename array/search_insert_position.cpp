#include "./../lc.h"

int solution(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    // the desired index is between [left, right + 1]
    while(left <= right) {
        int mid = (left + right) / 2;
        if(target == nums[mid])
            return mid;
         else if(target > nums[mid])
            left = mid + 1;
        else 
            right = mid - 1;
    }

    // at this point, left > right. that is left >= right + 1
    // left <= right + 1, so we know left == right + 1;
    return left;
}

int main(int argc, char **argv) {
    vector<int> nums1 = {1, 3, 5, 6};
    int res1 = solution(nums1, 5);
    int res2 = solution(nums1, 2);
    std::cout << "done.";
    return 0;
}