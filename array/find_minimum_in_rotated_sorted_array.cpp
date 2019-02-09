#include "./../lc.h"

int solution(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < nums[right])
            right = mid;
        else if(nums[mid] > nums[right])
            left = mid + 1;
    }
    return nums[left];
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}