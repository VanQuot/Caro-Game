#include "../../../include/bll/ai/SimpleAI.h"
#include "../../../include/bll/ai/BoardEvaluator.h"
#include "../../../include/shared/types/GameConstants.h"

Position getSimpleAIMove(int *board, int size, int winLen)
{
    Position best = {-1, -1};
    int bestScore = -1;

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            if (B(board, r, c, size) != EMPTY)
                continue;

            int atkScore = scoreMove(board, size, winLen, r, c, AI_PIECE);
            int defScore = scoreMove(board, size, winLen, r, c, PLAYER);
            int total = atkScore + defScore;

            if (total > bestScore)
            {
                bestScore = total;
                best = {r, c};
            }
        }
    }

    if (best.row == -1)
        best = {size / 2, size / 2};
    return best;
}