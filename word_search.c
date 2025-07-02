#include <stdio.h>
#include <stdbool.h>

bool backtrack(char** board, int rows, int cols, char* word, int i, int j, int n) {
    if (word[n] == '\0') {
        return true;
    }

    if (i < 0 || i >= rows || j < 0 || j >= cols)
        return false;

    if (board[i][j] != word[n]) {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '\0';
    bool found = backtrack (board, rows, cols, word, i+1, j, n+1) || backtrack (board, rows, cols, word, i-1, j, n+1) || backtrack (board, rows, cols, word, i, j+1, n+1) || backtrack (board, rows, cols, word, i, j-1, n+1);

    board[i][j] = temp;  
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {

    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardColSize[0]; j++) {
            if (backtrack(board, boardSize, *boardColSize, word, i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}
void main() {
    char** board[][4] = {{"A","B","C","E"}, {"S","F","C","S"}, {"A","D","E","E"}};
    int boardSize = 3;
    int* boardColSize = {4, 4, 4};
    char* word = "ABCCED";
    
}
