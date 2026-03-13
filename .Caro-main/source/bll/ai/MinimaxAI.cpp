#include "../../../include/bll/ai/MinimaxAI.h"
#include "../../../include/bll/ai/BoardEvaluator.h"
#include "../../../include/shared/utils/Utils.h"
#include "../../../include/shared/types/GameConstants.h"
#include <climits>

static int MINIMAX_SIZE;
static int MINIMAX_WIN;

static int evaluateBoard(int *board)
{
    int score = 0;
    for (int r = 0; r < MINIMAX_SIZE; r++)
        for (int c = 0; c < MINIMAX_SIZE; c++)
        {
            int p = B(board, r, c, MINIMAX_SIZE);
            if (p == AI_PIECE)
                score += scoreMove(board, MINIMAX_SIZE, MINIMAX_WIN, r, c, AI_PIECE);
            else if (p == PLAYER)
                score -= scoreMove(board, MINIMAX_SIZE, MINIMAX_WIN, r, c, PLAYER);
        }
    return score;
}

static bool isCandidate(int *board, int r, int c)
{
    int radius = 2;
    for (int dr = -radius; dr <= radius; dr++)
        for (int dc = -radius; dc <= radius; dc++)
        {
            int nr = r + dr, nc = c + dc;
            if (isInBounds(nr, nc, MINIMAX_SIZE) && B(board, nr, nc, MINIMAX_SIZE) != EMPTY)
                return true;
        }
    return false;
}

static int minimax(int *board, int depth, bool isMaximizing)
{
    // Kiem tra thang nhanh
    int winner = 0;
    int dirs[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    for (int r = 0; r < MINIMAX_SIZE && winner == 0; r++)
        for (int c = 0; c < MINIMAX_SIZE && winner == 0; c++)
        {
            int p = B(board, r, c, MINIMAX_SIZE);
            if (p == EMPTY)
                continue;
            for (int d = 0; d < 4; d++)
            {
                int cnt = 1;
                for (int i = 1; i < MINIMAX_WIN; i++)
                {
                    int nr = r + dirs[d][0] * i, nc = c + dirs[d][1] * i;
                    if (!isInBounds(nr, nc, MINIMAX_SIZE) ||
                        B(board, nr, nc, MINIMAX_SIZE) != p)
                        break;
                    cnt++;
                }
                if (cnt >= MINIMAX_WIN)
                {
                    winner = p;
                    break;
                }
            }
        }

    if (winner == AI_PIECE)
        return 100000;
    if (winner == PLAYER)
        return -100000;
    if (depth == 0)
        return evaluateBoard(board);

    if (isMaximizing)
    {
        int best = INT_MIN;
        for (int r = 0; r < MINIMAX_SIZE; r++)
            for (int c = 0; c < MINIMAX_SIZE; c++)
            {
                if (B(board, r, c, MINIMAX_SIZE) != EMPTY)
                    continue;
                if (!isCandidate(board, r, c))
                    continue;
                B(board, r, c, MINIMAX_SIZE) = AI_PIECE;
                int val = minimax(board, depth - 1, false);
                B(board, r, c, MINIMAX_SIZE) = EMPTY;
                if (val > best)
                    best = val;
            }
        return (best == INT_MIN) ? 0 : best;
    }
    else
    {
        int best = INT_MAX;
        for (int r = 0; r < MINIMAX_SIZE; r++)
            for (int c = 0; c < MINIMAX_SIZE; c++)
            {
                if (B(board, r, c, MINIMAX_SIZE) != EMPTY)
                    continue;
                if (!isCandidate(board, r, c))
                    continue;
                B(board, r, c, MINIMAX_SIZE) = PLAYER;
                int val = minimax(board, depth - 1, true);
                B(board, r, c, MINIMAX_SIZE) = EMPTY;
                if (val < best)
                    best = val;
            }
        return (best == INT_MAX) ? 0 : best;
    }
}

Position getMinimaxAIMove(int *board, int size, int winLen)
{
    MINIMAX_SIZE = size;
    MINIMAX_WIN = winLen;

    Position best = {size / 2, size / 2};
    int bestScore = INT_MIN;
    int depth = 3;

    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
        {
            if (B(board, r, c, size) != EMPTY)
                continue;
            if (!isCandidate(board, r, c))
                continue;
            B(board, r, c, size) = AI_PIECE;
            int score = minimax(board, depth - 1, false);
            B(board, r, c, size) = EMPTY;
            if (score > bestScore)
            {
                bestScore = score;
                best = {r, c};
            }
        }
    return best;
}