#include "./../lc.h"

bool solution(string s, vector<string> &wordDict) {
    if(wordDict.empty()) return false;

    int n = s.size();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for(int i = 1; i <= n; ++i) {
        for(int j = i - 1; j >=0; --j) {
            if(dp[j]) {
                string word = s.substr(j, i - j);
                if(dict.find(word) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[n];
}

int main(int argc, char **argv) {
    string s1 = "leetcode";
    vector<string> dict1 = {"leet", "code"};
    bool res1 = solution(s1, dict1);
    std::cout << "done.";
    return 0;
}