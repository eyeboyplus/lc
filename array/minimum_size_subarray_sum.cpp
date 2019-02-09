#include "./../lc.h"

// 双指针法
int solution_1(int s, vector<int> &nums) {
    int left = 0, n = nums.size(), sum = 0, len = INT_MAX;
    for(int right = 0; right < n; ++right) {
        sum += nums[right];
        while(sum >= s) {
            len = min(len, right - left + 1);
            sum -= nums[left++];
        }
    }
    return len == INT_MAX ? 0 :len;
}

// 二分查找法
int solution_2(int s, vector<int> &nums) {
   int n = nums.size();
    vector<int> sums(n + 1, 0);
    for(int i = 1; i < n + 1; i++)
        sums[i] = sums[i - 1] + nums[i - 1];
    int len = INT_MAX;
    for(int i = n - 1; i >= 0 && sums[i] >= s; i--) {
        int j = upper_bound(sums.begin(), sums.begin() + i, sums[i] - s) - sums.begin();
        len = min(len, i - j + 1);
    }
    return len == INT_MAX ? 0 : len;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}