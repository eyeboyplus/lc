#include "./../lc.h"

void solution(vector<vector<int>> &matrix) {
    reverse(matrix.begin(), matrix.end());
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

int main(int argc, char **argv) {
    vector<vector<int>> matrix1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    solution(matrix1);
    std::cout << "done.";
    return 0;
}