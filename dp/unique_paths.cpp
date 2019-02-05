#include "./../lc.h"

// 未优化版
int solution_1(int m, int n) {
    vector<vector<int>> path(m, vector<int>(n, 1));
    for(int i = 1; i < m; i ++) 
        for(int j = 1; j < n; j ++)
            path[i][j] = path[i - 1][j] + path[i][j - 1];
    return path[m - 1][n - 1];
}

// 优化1 ??
// 每次更新path[i][j],只需要path[i-1][j]（同一列，上一行）和path[i][j-1]（左一列）
// 可以值维护两列数据来完成整个过程
int solution_2(int m, int n) {
    if(m > n) return solution_2(n, m);
    vector<int> prev(m, 1);
    vector<int> cur(m, 1);
    for(int j = 1; j < n; j++)
        for(int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + prev[i];
        swap(prev, cur);
    return prev[m - 1];
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}