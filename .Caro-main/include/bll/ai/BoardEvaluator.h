#ifndef _BOARDEVALUATOR_H_
#define _BOARDEVALUATOR_H_

// ============================================================
//  Ham danh gia dung chung cho Gomoku (size=15, win=5)
//  va TicTacToe (size=3, win=3)
// ============================================================

// Cham diem mot huong (dr,dc) xuat phat tu (row,col) cho player
// Tra ve diem dua tren so quan lien tiep va so dau mo
int scoreDirection(int *board, int size, int winLen,
                   int row, int col, int dr, int dc, int player);

// Tong diem cua player tai o (row,col) neu dat quan vao do
int scoreMove(int *board, int size, int winLen,
              int row, int col, int player);

#endif // !_BOARDEVALUATOR_H_