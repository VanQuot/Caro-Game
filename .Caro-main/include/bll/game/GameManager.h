#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "../../shared/utils/Utils.h"
#include "../../shared/types/GameConstants.h"

enum GameMode
{
    PVP = 1,
    PVC = 2
};

enum GameType
{
    GOMOKU = 1,
    TICTACTOE = 2
};

enum Difficulty
{
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
};

struct GameState
{
    int board[GOMOKU_SIZE * GOMOKU_SIZE]; // mang 1 chieu, truy cap bang B(r,c,size)
    int size;                             // 15 hoac 3
    int winLen;                           // 5 hoac 3
    int currentTurn;                      // 1 = Player1/Player, 2 = Player2/AI
    bool gameOver;
    int winner; // 0=chua, 1=P1, 2=P2/AI, 3=hoa
    GameMode mode;
    GameType type;
    Difficulty difficulty;
    char player1Name[32];
    char player2Name[32];
};

void initGame(GameState &gs, GameMode mode, GameType type, Difficulty diff,
              const char *p1, const char *p2);
void resetBoard(GameState &gs);
bool makeMove(GameState &gs, int row, int col); // tra ve false neu nuoc khong hop le
void doAITurn(GameState &gs);

#endif // !_GAMEMANAGER_H_