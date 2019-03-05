#include "./../lc.h"

int solution(string s) {
    if(s.empty()) return 0;
    unordered_map<char, int> map;
    int length = s.length(), maxLen = 0;
    for(int i = 0, j = 0; i < length; ++i) {
        if(map.find(s[i]) != map.end()) {
            j = max(j, map[s[i]] + 1);
        }
        map[s[i]] = i;
        maxLen = max(maxLen, i - j + 1);
    }
    return maxLen;
}

int main(int argc, char **argv) {
    int res1 = solution("abcabcbb");
    int res2 = solution("bbbbb");
    std::cout << "done.";
    return 0;
}