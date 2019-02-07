#include "./../lc.h"

void solution(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool isZeroCol = false;
    bool isZeroRow = false;
    for(int i = 0; i < m; ++i)          // 检查第一列
        if(matrix[i][0] == 0) {
            isZeroCol = true;
            break;
        }
    for(int i = 0; i < n; i++)          // 检查第一行
        if(matrix[0][i] == 0) {
            isZeroRow = true;
            break;
        }
    for(int i = 1; i < m; ++i) {        // 检查所有非第一行和非第一列的元素，并将零元素所在行的首元素和所在列的首元素置为0
        for(int j = 1; j < n; ++j) {
            if(matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
        }
    }
    for(int i = 1; i < m; ++i) {            // 遍历所有非第一行和非第一列的元素
        for(int j = 1; j < n; ++j) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if(isZeroCol)       // 处理第一列元素
        for(int i = 0; i < m; ++i) matrix[i][0] = 0;
    if(isZeroRow)       // 处理第一行元素
        for(int i = 0; i < n; ++i) matrix[0][i] = 0;
}

int main(int argc, char **argv) {
    vector<vector<int>> matrix1 = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    solution(matrix1);
    vector<vector<int>> matrix2 = {
        {1,1,1},
        {0, 1, 2},
    };
    solution(matrix2);
    std::cout << "done.";
    return 0;
}