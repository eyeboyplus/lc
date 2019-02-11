#include "./../lc.h"

int liveNeighbors(vector<vector<int>> &board, int i, int j) {
    int m = board.size(), n = m ? board[0].size() : 0;
    int lives = 0;
    for(int x = max(i - 1, 0); x <= min(i + 1, m - 1); x++) {
        for(int y = max(j - 1, 0); y <= min(j + 1, n - 1); y++) {
            lives += (board[x][y] & 1);
        }
    }
    lives -= board[i][j] & 1;
    return lives;
}

void solution(vector<vector<int>> &board) {
    int m = board.size(), n = m ? board[0].size() : 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int lives = liveNeighbors(board, i, j);
            if(board[i][j] == 1 && lives >= 2 && lives <= 3)
                board[i][j] = 3;    // 01 ---> 11
            if(board[i][j] == 0 && lives == 3)
                board[i][j] = 2;
        }
    }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            board[i][j] >>= 1;
}

int main(int argc, char **argv) {
    vector<vector<int>> board {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    solution(board);
    std::cout << "done.";
    return 0;
}