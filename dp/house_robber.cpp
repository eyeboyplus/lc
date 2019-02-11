#include "./../lc.h"


// iterative +memo (bottom-up)
int solution_1(vector<int> &nums) {
    int n = nums.size();
    if(n == 0) return 0;
    vector<int> memo (n + 1);
    memo[0] = 0;
    memo[1] = nums[0];
    for(int i = 1; i < n; ++i) {
        memo[i + 1] = max(memo[i], memo[i - 1] + 1);
    }
    return memo[n];
}

// iterative + 2 variables (bottom-up)
int solution_2(vector<int> &nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int prev1 = 0, prev2 = 0;
    for(int i = 0; i < n; ++i) {
        int tmp = prev1;
        prev1 = max(prev2 + nums[i], prev1);
        prev2 = tmp;
    }
    return prev1;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}