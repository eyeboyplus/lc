#include "./../lc.h"

bool dfs(const vector<vector<char>> &board, int i, int j,
    vector<vector<bool>> &visited, const string &word, int idx) {
    if(idx == word.size())
        return true;
    if(i < 0 || i == board.size() ||
        j < 0 || j == board[0].size())
        return false;
    if(visited[i][j]) return false;
    if(board[i][j] != word[idx]) return false;

    visited[i][j] = true;
    bool ret = dfs(board, i - 1, j, visited, word, idx + 1) // up
    || dfs(board, i + 1, j, visited, word, idx + 1)       // down
    || dfs(board, i, j - 1, visited, word, idx + 1)       // left
    || dfs(board, i, j + 1, visited, word, idx + 1);      // right
    visited[i][j] = false;
    return ret;
}

bool solution(vector<vector<char>> &board, string word) {
    int m = board.size();
    if(m == 0)
        return false;
    int n = board[0].size();
    if(n == 0)
        return false;
    vector<vector<bool>> visited = vector<vector<bool>> (m, vector<bool>(n, false));
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(dfs(board, i, j, visited, word, 0))
                return true;
    return false;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}