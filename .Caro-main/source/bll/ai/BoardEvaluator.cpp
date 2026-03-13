#include "../../../include/bll/ai/BoardEvaluator.h"
#include "../../../include/shared/utils/Utils.h"
#include "../../../include/shared/types/GameConstants.h"

// Dem quan lien tiep va kiem tra dau co mo
// Tra ve: <so_quan_lien_tiep, so_dau_mo>
static void analyzeDir(int *board, int size,
                       int row, int col, int dr, int dc, int player,
                       int &count, int &openEnds)
{
    count = 1;
    openEnds = 0;

    // Chieu xuoi
    int r = row + dr, c = col + dc;
    while (isInBounds(r, c, size) && B(board, r, c, size) == player)
    {
        count++;
        r += dr;
        c += dc;
    }
    if (isInBounds(r, c, size) && B(board, r, c, size) == EMPTY)
        openEnds++;

    // Chieu nguoc
    r = row - dr;
    c = col - dc;
    while (isInBounds(r, c, size) && B(board, r, c, size) == player)
    {
        count++;
        r -= dr;
        c -= dc;
    }
    if (isInBounds(r, c, size) && B(board, r, c, size) == EMPTY)
        openEnds++;
}

int scoreDirection(int *board, int size, int winLen,
                   int row, int col, int dr, int dc, int player)
{
    int count, openEnds;
    analyzeDir(board, size, row, col, dr, dc, player, count, openEnds);

    if (count >= winLen)
        return 1000000;
    if (openEnds == 0)
        return 0;

    if (count == winLen - 1)
        return (openEnds == 2) ? 50000 : 10000;
    if (count == winLen - 2)
        return (openEnds == 2) ? 5000 : 1000;
    if (count == winLen - 3)
        return (openEnds == 2) ? 500 : 100;
    return (openEnds == 2) ? 50 : 10;
}

int scoreMove(int *board, int size, int winLen,
              int row, int col, int player)
{
    int original = B(board, row, col, size); // luu trang thai cu
    B(board, row, col, size) = player;

    int dirs[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    int total = 0;
    for (int d = 0; d < 4; d++)
    {
        total += scoreDirection(board, size, winLen,
                                row, col, dirs[d][0], dirs[d][1], player);
    }

    B(board, row, col, size) = original; // hoan tac ve trang thai cu
    return total;
}