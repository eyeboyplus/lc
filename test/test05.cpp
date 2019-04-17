#include "./../lc.h"

bool recursive(char* matrix, int rows, int cols, int i, int j, bool *board,
               char *str, int k) {
    if(*(str + k) == '\0') return true;
    if(i < 0 || i >= rows) return false;
    if(j < 0 || j >= cols) return false;
    if(board[i * cols + j]) return false;
    
    if(matrix[i * cols + j] != str[k]) return false;
    
    board[i* cols + j] = true;
    // up
    bool flag = recursive(matrix, rows, cols, i - 1, j, board, str, k++)
    || recursive(matrix, rows, cols, i + 1, j, board, str, k++)
    || recursive(matrix, rows, cols, i, j - 1, board, str, k++)
    || recursive(matrix, rows, cols, i, j + 1, board, str, k++);
    board[i * cols + j] = false;
    return flag;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    bool board[rows * cols];
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(recursive(matrix, rows, cols, 0, 0, board, str, 0))
                return true;
    return false;
}

int main(int argc, char **argv) {
    char matrix[] = "ABCESFCSADEE";
    char str[] = "ABCCED";
    bool ret = hasPath(matrix, 3, 4, str);
    std::cout << "done.";
    return 0;
}