#include "./../lc.h"

void backtracking(vector<string> &result, string path, int level, string s, int idx) {
    if(level > 4) return;
    if(level == 4 && idx == s.length()) {
        result.push_back(path);
        return;
    }

    int length = s.length();
    for(int i = 1; i <= 3; ++i) {
        if(idx + i - 1 >= length) break;
        string ss = s.substr(idx, i);
        if((ss[0] == '0' && ss.size() > 1) || stoi(ss) > 255) continue;
        backtracking(result, path + ss + (level < 3 ? "." : ""), level + 1, s, idx + i);
    }
}

vector<string> solution(string s) {
    vector<string> result;
    string path;
    backtracking(result, path, 0, s, 0);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}