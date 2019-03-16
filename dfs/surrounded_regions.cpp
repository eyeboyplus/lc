#include "./../lc.h"

void check(vector<vector<char>> &matrix, int i, int j, int row, int col) {
    if(matrix[i][j] == 'O') {
        matrix[i][j] = '1';
        if(i > 1)
            check(matrix, i - 1, j, row, col);
        if(j > 1)
            check(matrix, i, j - 1, row, col);
        if(i + 1 < row)
            check(matrix, i + 1, j, row, col);
        if(j + 1 < col)
            check(matrix, i, j + 1, row, col);
    }       
}

void solution(vector<vector<char>> &board) {
    if(board.empty()) return;
    int m = board.size();
    int n = board[0].size();

    for(int i = 0; i < m; i++) {
        check(board, i, 0, m, n);
        if(n > 1)
            check(board, i, n - 1, m, n);
    }
        
    for(int j = 1; j + 1 < n; j++) {
        check(board, 0, j, m, n);
        if(n > 1)
            check(board, n - 1, j, m, n);
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 'O')
                board[i][j] = 'X';
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == '1')
                board[i][j] = 'O';
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}