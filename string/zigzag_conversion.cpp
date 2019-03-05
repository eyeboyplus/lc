#include "./../lc.h"

string solution(string s, int numRows) {
    int length = s.length();
    vector<string> vec(numRows, "");
    for(int i = 0; i < length;) {
        for(int idx = 0; idx < numRows && i < length; ++idx)
            vec[idx].push_back(s[i++]);
        for(int idx = numRows - 2; idx >= 1 && i < length; --idx)
            vec[idx].push_back(s[i++]);
    }
    string result;
    for(int idx = 0; idx < numRows; ++idx)
        result += vec[idx];
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}