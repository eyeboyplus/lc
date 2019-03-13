#include "./../lc.h"

int solution(vector<vector<char>> &matrix) {
    if(matrix.empty()) return 0;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> height(n, 0), left(n, 0), right(n, n);
    int maxArea = 0;
    for(int i = 0; i < m; i ++) {
        // height
        for(int j = 0; j < n; ++j)
            if(matrix[i][j] == '0')
                height[j] = 0;
            else
                height[j] ++;
        // left
        for(int j = 0; j < n; j ++)
            if(matrix[i][j] == '1')
                left[j] = max(left[j], j);
            else
                left[j] = 0;
        // right
        for(int j = n - 1; j >= 0; --j)
            if(matrix[i][j] == '1')
                right[j] = min(right[j], j + 1);
            else
                right[j] = n;
        // area
        for(int j = 0; j < n; j++)
            maxArea = max(maxArea, (right[j] - left[i]) * height[j]);
    }
    return maxArea;
}

int main(int argc, char **argv) {
    vector<vector<char>> matrix1 = {
          {'0','0','0','0','0'},
  {'0','0','0','0','0'},
  {'0','0','0','0','0'},
  {'0','0','0','0','0'}
    };
    int res = solution(matrix1);
    std::cout << "done.";
    return 0;
}