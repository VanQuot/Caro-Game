#ifndef _GAMECONSTANTS_H_
#define _GAMECONSTANTS_H_

const int GOMOKU_SIZE = 15;
const int TICTACTOE_SIZE = 3;
const int WIN_GOMOKU = 5;
const int WIN_TICTACTOE = 3;

const int EMPTY = 0;
const int PLAYER = 1;
const int AI_PIECE = 2;

// Macro truy cap mang board 1 chieu nhu mang 2 chieu
// Dung: B(board, r, c, size) thay cho board[r][c]
#define B(board, r, c, size) (board)[(r) * (size) + (c)]

#endif // !_GAMECONSTANTS_H_