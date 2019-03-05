#include "./../lc.h"

string solution(vector<string>& strs) {
    if(strs.empty()) return "";
    int n = strs.size();

    if(n == 1) return strs[0];

    string result = "";
    for(int i = 0; i < strs[0].size(); ++i) {
        for(int j = 1; j < n; ++j) {
            if(i < strs[j].size() && strs[j][i] == strs[0][i])
                continue;
            else
                return result;
        }
        result.push_back(strs[0][i]);
    }
    return result;
}

int main(int argc, char **argv) {
    vector<string> vec1 = {"flower","flow","flight"};
    string res1 = solution(vec1);
    vector<string> vec2 = {"dog","racecar","car"};
    string res2 = solution(vec2);
    vector<string> vec3 = {"aa", "ab"};
    string res3 = solution(vec3);
    std::cout << "done.";
    return 0;
}