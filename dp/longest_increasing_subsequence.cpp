#include "./../lc.h"

// dp
int solution_1(vector<int> &nums) {
    int n = nums.size();
    if(n == 0) return 0;

    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(nums[j] < nums[i])
                dp[i] = max(dp[j] + 1, dp[i]);
    int result = 0;
    for(int i = 0; i < n; ++i)
        result = max(result, dp[i]);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}