#include "./../lc.h"

int solution(string s) {
    if(s.empty()) return 0;
    int n = s.size();
    vector<int> dp (n + 1, 0);
    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : 0;
    for(int i = 2; i <= n; ++i) {
        int first = stoi(s.substr(i - 1, 1));
        int second = stoi(s.substr(i - 2, 2));
        if(first >= 1 && first <= 9)
            dp[i] += dp[i - 1];
        if(second >= 10 && second <= 26)
            dp[i] += dp[i - 2];
    }
    return dp[n];
}

int main(int argc, char **argv) {
    string s1 = "12";
    int res1 = solution(s1);
    string s2 = "226";
    int res2 = solution(s2);
    std::cout << "done.";
    return 0;
}