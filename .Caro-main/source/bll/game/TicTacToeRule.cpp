#include "../../../include/bll/game/TicTacToeRule.h"
#include "../../../include/shared/utils/Utils.h"
#include "../../../include/shared/types/GameConstants.h"

int countDirTTT(int *board, int size,
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

int checkWinTicTacToe(int *board, int size)
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
                int cnt = 1 + countDirTTT(board, size, r, c, dr, dc, p) + countDirTTT(board, size, r, c, -dr, -dc, p);
                if (cnt >= WIN_TICTACTOE)
                    return p;
            }
        }
    }
    return 0;
}

bool checkDrawTicTacToe(int *board, int size)
{
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            if (B(board, r, c, size) == EMPTY)
                return false;
    return true;
}