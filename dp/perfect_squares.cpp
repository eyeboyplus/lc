#include "./../lc.h"

int solution(int n) {
    if(n <= 0) return 0;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main(int argc, char **argv) {
    int res1 = solution(12);
    std::cout << "done.";
    return 0;
}