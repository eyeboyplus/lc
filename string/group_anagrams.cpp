#include "./../lc.h"

vector<vector<string>> solution(vector<string> &strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> map;
    for(string s : strs) {
        string t = s;
        sort(t.begin(), t.end());
        map[t].push_back(s);
    }
    for(auto p : map)
        result.push_back(p.second);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}