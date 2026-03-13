#include "../../../include/bll/game/GomokuRule.h"
#include "../../../include/shared/utils/Utils.h"
#include "../../../include/shared/types/GameConstants.h"

int countDirGMK(int *board, int size,
             int row, int col, int dr, int dc, int player)
{
    int count = 0;
    int r = row + dr, c = col + dc;
    while (isInBounds(r, c, size) && B(board, r, c, size) == player)
    {
        count++;
        r += dr;
        c += dc;
    }
    return count;
}

// Kiem tra tung o - neu la nguon goc cua day 5 (chinh xac) thi thang
int checkWinGomoku(int *board, int size)
{
    int dirs[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int p = B(board, r, c, size);
            if (p == EMPTY)
                continue;

            for (int d = 0; d < 4; d++)
            {
                int dr = dirs[d][0], dc = dirs[d][1];
                int cnt = 1 + countDirGMK(board, size, r, c, dr, dc, p) + countDirGMK(board, size, r, c, -dr, -dc, p);
                if (cnt == WIN_GOMOKU)
                    return p; // chinh xac 5
            }
        }
    }
    return 0;
}

bool checkDrawGomoku(int *board, int size)
{
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            if (B(board, r, c, size) == EMPTY)
                return false;
    return true;
}