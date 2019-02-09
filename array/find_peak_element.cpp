#include "./../lc.h"

int solution(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while(low < high) {
        int mid = (low + high) / 2;
        if(nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main(int argc, char **argv) {
    vector<int> nums1 = {1,2,3,1};
    int res1 = solution(nums1);

    vector<int> nums2 = {1,2,1,3,5,6,4};
    int res2 = solution(nums2);

    std::cout << "done.";
    return 0;
}