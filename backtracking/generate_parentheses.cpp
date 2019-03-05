#include "./../lc.h"

void backtrack(vector<string> &result, string path, int open, int close, int max) {
    if(path.length() == max * 2) {
        result.push_back(path);
        return;
    }

    if(open < max)
        backtrack(result, path + "(", open + 1, close, max);
    if(close < open)
        backtrack(result, path + ")", open, close + 1, max);
}

vector<string> solution(int n) {
    vector<string> result;
    string path;
    backtrack(result, path, 0, 0, n);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}