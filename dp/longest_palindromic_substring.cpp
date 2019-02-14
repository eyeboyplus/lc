#include "./../lc.h"

string solution(string s) {
    int n = s.size();

    int len = INT_MIN, start = -1;

    vector<vector<bool>> dp (n, vector<bool>(n, false));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]);

            if(dp[i][j] && (len == INT_MIN || j - i + 1 > len)) {
                start = i;
                len = j - i + 1;
            }
        }
    }
    return s.substr(start, len);
}

int main(int argc, char **argv) {
    string s1 = "babad";
    string res1 = solution(s1);
    string s2 = "cbbd";
    string res2 = solution(s2);
    std::cout << "done.";
    return 0;
}