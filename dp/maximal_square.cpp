#include "./../lc.h"

int solution_1(vector<vector<char>> &matrix) {
    if(matrix.empty()) return 0;

    int m = matrix.size(), n = matrix[0].size(), sz = 0;
    vector<vector<int>> dp(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0 || matrix[i][j] == '0')
                dp[i][j] = matrix[i][j] - '0';
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;  // 画图+归纳
            sz = max(dp[i][j], sz);
        }
    }
    return sz * sz;
}

// 优化
int solution_2(vector<vector<char>> &matrix) {
    if(matrix.empty()) return 0;

    int m = matrix.size(), n = matrix[0].size(), sz = 0;
    vector<int> prev(n, 0), cur(n, 0);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == 0 || j == 0 || matrix[i][j] == '0')
                cur[j] = matrix[i][j] - '0';
            else
                cur[j] = min(prev[j - 1], min(prev[j], cur[j - 1])) + 1;
            sz = max(cur[j], sz);
        }
        fill(prev.begin(), prev.end(), 0);
        swap(prev, cur);
    }
    return sz * sz;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}