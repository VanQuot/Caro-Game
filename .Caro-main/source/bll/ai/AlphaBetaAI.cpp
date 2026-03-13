#include "../../../include/bll/ai/AlphaBetaAI.h"
#include "../../../include/bll/ai/BoardEvaluator.h"
#include "../../../include/shared/utils/Utils.h"
#include "../../../include/shared/types/GameConstants.h"
#include <climits>

static int AB_SIZE;
static int AB_WIN;

static int evalBoard(int *board)
{
    int score = 0;
    for (int r = 0; r < AB_SIZE; r++)
        for (int c = 0; c < AB_SIZE; c++)
        {
            int p = B(board, r, c, AB_SIZE);
            if (p == AI_PIECE)
                score += scoreMove(board, AB_SIZE, AB_WIN, r, c, AI_PIECE);
            else if (p == PLAYER)
                score -= scoreMove(board, AB_SIZE, AB_WIN, r, c, PLAYER);
        }
    return score;
}

static bool checkWinner(int *board, int player)
{
    int dirs[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    for (int r = 0; r < AB_SIZE; r++)
        for (int c = 0; c < AB_SIZE; c++)
        {
            if (B(board, r, c, AB_SIZE) != player)
                continue;
            for (int d = 0; d < 4; d++)
            {
                int cnt = 1;
                for (int i = 1; i < AB_WIN; i++)
                {
                    int nr = r + dirs[d][0] * i, nc = c + dirs[d][1] * i;
                    if (!isInBounds(nr, nc, AB_SIZE) ||
                        B(board, nr, nc, AB_SIZE) != player)
                        break;
                    cnt++;
                }
                if (cnt >= AB_WIN)
                    return true;
            }
        }
    return false;
}

static bool isCandidate(int *board, int r, int c)
{
    for (int dr = -2; dr <= 2; dr++)
        for (int dc = -2; dc <= 2; dc++)
        {
            int nr = r + dr, nc = c + dc;
            if (isInBounds(nr, nc, AB_SIZE) && B(board, nr, nc, AB_SIZE) != EMPTY)
                return true;
        }
    return false;
}

static int alphaBeta(int *board, int depth,
                     int alpha, int beta, bool isMaximizing)
{
    if (checkWinner(board, AI_PIECE))
        return 100000 + depth;
    if (checkWinner(board, PLAYER))
        return -100000 - depth;
    if (depth == 0)
        return evalBoard(board);

    if (isMaximizing)
    {
        int best = INT_MIN;
        for (int r = 0; r < AB_SIZE; r++)
            for (int c = 0; c < AB_SIZE; c++)
            {
                if (B(board, r, c, AB_SIZE) != EMPTY)
                    continue;
                if (!isCandidate(board, r, c))
                    continue;
                B(board, r, c, AB_SIZE) = AI_PIECE;
                int val = alphaBeta(board, depth - 1, alpha, beta, false);
                B(board, r, c, AB_SIZE) = EMPTY;
                if (val > best)
                    best = val;
                if (val > alpha)
                    alpha = val;
                if (beta <= alpha)
                    goto done_max;
            }
    done_max:
        return (best == INT_MIN) ? 0 : best;
    }
    else
    {
        int best = INT_MAX;
        for (int r = 0; r < AB_SIZE; r++)
            for (int c = 0; c < AB_SIZE; c++)
            {
                if (B(board, r, c, AB_SIZE) != EMPTY)
                    continue;
                if (!isCandidate(board, r, c))
                    continue;
                B(board, r, c, AB_SIZE) = PLAYER;
                int val = alphaBeta(board, depth - 1, alpha, beta, true);
                B(board, r, c, AB_SIZE) = EMPTY;
                if (val < best)
                    best = val;
                if (val < beta)
                    beta = val;
                if (beta <= alpha)
                    goto done_min;
            }
    done_min:
        return (best == INT_MAX) ? 0 : best;
    }
}

Position getAlphaBetaAIMove(int *board, int size, int winLen)
{
    AB_SIZE = size;
    AB_WIN = winLen;

    Position best = {size / 2, size / 2};
    int bestScore = INT_MIN;
    int depth = 5;

    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
        {
            if (B(board, r, c, size) != EMPTY)
                continue;
            if (!isCandidate(board, r, c))
                continue;
            B(board, r, c, size) = AI_PIECE;
            int score = alphaBeta(board, depth - 1, INT_MIN, INT_MAX, false);
            B(board, r, c, size) = EMPTY;
            if (score > bestScore)
            {
                bestScore = score;
                best = {r, c};
            }
        }
    return best;
}