#include "./../lc.h"

bool solution(vector<vector<int>> &matrix, int target) {
    if(matrix.empty())
        return false;
        
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (matrix[mid / n][mid % n] == target)
            return true;
        else if(matrix[mid / n][mid % n] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main(int argc, char **argv) {
    vector<vector<int>> matrix1 = {
  {1,   3,  5,  7},
  {10, 11, 16, 20},
  {23, 30, 34, 50}
};
    bool res1 = solution(matrix1, 3);
    vector<vector<int>> matrix2 = {
  {1,   3,  5,  7},
  {10, 11, 16, 20},
  {23, 30, 34, 50}
};
    bool res2 = solution(matrix2, 13);
    std::cout << "done.";
    return 0;
}