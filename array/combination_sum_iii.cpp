#include "./../lc.h"

void recursive(int k, int sum, int n, int start, vector<int> path,
    vector<vector<int>> &result) {
    if(path.size() == k) {
        if(sum == n)
            result.push_back(path);
        return;
    }
    for(int i = start; i <= 9; ++i) {
        path.push_back(i);
        recursive(k, sum + i, n, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> solution(int k, int n) {
    int sum = 0;
    vector<int> path;
    vector<vector<int>> result;
    recursive(k, sum, n, 1, path, result);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}