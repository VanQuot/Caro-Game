#ifndef _GOMOKURULE_H_
#define _GOMOKURULE_H_

// Kiem tra thang theo luat Gomoku (chinh xac 5, khong tinh 6+)
// Tra ve: 1 neu PLAYER thang, 2 neu AI thang, 0 neu chua co
int checkWinGomoku(int *board, int size);

// Kiem tra hoa (day ban co)
bool checkDrawGomoku(int *board, int size);

// Dem quan lien tiep tu (row,col) theo huong (dr,dc)
int countDirGMK(int *board, int size,
             int row, int col, int dr, int dc, int player);

#endif // !_GOMOKURULE_H_