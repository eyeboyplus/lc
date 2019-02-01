#include "./../lc.h"

int solution(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int diff = INT_MAX, result;
    for(int i = 0; i < n; ++i) {
        int j = i + 1, k = n - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == target) {
                return sum;
            } else if(sum > target) {
                k --;
            } else {
                j ++;
            }
            if (abs(target - sum) < diff) {
                diff = abs(target - sum);
                result = sum;
            }
        }
    }
    return result;
}

int main(int argc, char **argv) {
    vector<int> nums1 = {-1, 2, 1, -4};
    int res1 = solution(nums1, 1);
    std::cout << "done.";
    return 0;
}