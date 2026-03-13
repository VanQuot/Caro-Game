#ifndef _TICTACTOERULE_H_
#define _TICTACTOERULE_H_

// Su dung GOMOKU_SIZE cho kieu mang de nhat quan voi GameState.board
// Tham so size truyen vao se la TICTACTOE_SIZE (3) de dieu khien logic

int countDirTTT(int *board, int size,
                int row, int col, int dr, int dc, int player);

// Tra ve: 1 neu PLAYER thang, 2 neu AI thang, 0 neu chua co
int checkWinTicTacToe(int *board, int size);

bool checkDrawTicTacToe(int *board, int size);

#endif // !_TICTACTOERULE_H_