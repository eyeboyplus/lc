#include "./../lc.h"

vector<int> printMatrix(vector<vector<int> > matrix) {
    int m = matrix.size();
    int n = m ? matrix[0].size() : 0;
    int level = ((min(m, n) - 1) / 2) + 1;
    vector<int> result;
    for(int i = 0; i < level; i++) {
        // top
        for(int j = i; j <= n - 1 - i; j++)
            result.push_back(matrix[i][j]);
        // right
        for(int j = i + 1; j <= m - 1 - i - 1; j++)
            result.push_back(matrix[j][n - i - 1]);
        // bottom
        for(int j = n - 1; j >= i; j--)
            result.push_back(matrix[m - 1 - i][j]);
        // left
        for(int j = m - 1 - i - 1; j >= i + 1; j--)
            result.push_back(matrix[j][i]);
    }
    return result;
}

void print() {
    cout << "hello" << endl;    
}

class Test{
public:
    Test() {
        //::print();
    }
    ~Test() {
        ::print();
    }
};

Test test;

int main(int argc, char **argv) {
    
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {12, 13, 14, 5, 6},
        {11, 16, 15, 6, 7},
        {10, 9, 8, 7, 8},
    };

    vector<int> res = printMatrix(matrix);

    std::cout << "done.";
    return 0;
}