#include "../../../include/bll/game/GameManager.h"
#include "../../../include/bll/game/GomokuRule.h"
#include "../../../include/bll/game/TicTacToeRule.h"
#include "../../../include/bll/ai/SimpleAI.h"
#include "../../../include/bll/ai/MinimaxAI.h"
#include "../../../include/bll/ai/AlphaBetaAI.h"
#include <cstring>

void initGame(GameState &gs, GameMode mode, GameType type, Difficulty diff,
              const char *p1, const char *p2)
{
    gs.mode = mode;
    gs.type = type;
    gs.difficulty = diff;
    gs.size = (type == GOMOKU) ? GOMOKU_SIZE : TICTACTOE_SIZE;
    gs.winLen = (type == GOMOKU) ? WIN_GOMOKU : WIN_TICTACTOE;

    strncpy(gs.player1Name, p1, 31);
    strncpy(gs.player2Name, p2, 31);

    resetBoard(gs);
}

void resetBoard(GameState &gs)
{
    for (int i = 0; i < gs.size * gs.size; i++)
        gs.board[i] = EMPTY;
    gs.currentTurn = 1;
    gs.gameOver = false;
    gs.winner = 0;
}

// Kiem tra thang/hoa sau moi nuoc
static void checkGameOver(GameState &gs)
{
    if (gs.type == GOMOKU)
    {
        int w = checkWinGomoku(gs.board, gs.size);
        if (w != 0)
        {
            gs.winner = w;
            gs.gameOver = true;
            return;
        }
        if (checkDrawGomoku(gs.board, gs.size))
        {
            gs.winner = 3;
            gs.gameOver = true;
        }
    }
    else
    {
        int w = checkWinTicTacToe(gs.board, gs.size);
        if (w != 0)
        {
            gs.winner = w;
            gs.gameOver = true;
            return;
        }
        if (checkDrawTicTacToe(gs.board, gs.size))
        {
            gs.winner = 3;
            gs.gameOver = true;
        }
    }
}

bool makeMove(GameState &gs, int row, int col)
{
    if (gs.gameOver)
        return false;
    if (!isInBounds(row, col, gs.size))
        return false;
    if (B(gs.board, row, col, gs.size) != EMPTY)
        return false;

    B(gs.board, row, col, gs.size) = gs.currentTurn;
    checkGameOver(gs);

    if (!gs.gameOver)
        gs.currentTurn = (gs.currentTurn == 1) ? 2 : 1;

    return true;
}

void doAITurn(GameState &gs)
{
    if (gs.gameOver || gs.currentTurn != 2)
        return;

    Position pos;
    switch (gs.difficulty)
    {
    case EASY:
        pos = getSimpleAIMove(gs.board, gs.size, gs.winLen);
        break;
    case MEDIUM:
        pos = getMinimaxAIMove(gs.board, gs.size, gs.winLen);
        break;
    case HARD:
        pos = getAlphaBetaAIMove(gs.board, gs.size, gs.winLen);
        break;
    }
    makeMove(gs, pos.row, pos.col);
}