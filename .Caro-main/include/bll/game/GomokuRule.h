#ifndef _GOMOKURULE_H_
#define _GOMOKURULE_H_

#include "GameAction.h"

namespace GomokuRule 
{
    const short NULL_VALUE = 0;
    const short DRAW_VALUE = 1;
    const short WIN_VALUE  = 2;

    short GetGameState(
        const GameAction::Board& board,
        short moveCount,
        const GameAction::Point& move,
        short playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint
    );

    bool CheckDraw(
        const GameAction::Board& board,
        short moveCount
    );

    bool CheckVerticalWin(
        const GameAction::Board& board,
        const GameAction::Point& move,
        short playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint
    );

    bool CheckHorizontalWin(
        const GameAction::Board& board,
        const GameAction::Point& move,
        short playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint
    );

    bool CheckLeftDiagonalWin(
        const GameAction::Board& board,
        const GameAction::Point& move,
        short playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint
    );

    bool CheckRightDiagonalWin(
        const GameAction::Board& board,
        const GameAction::Point& move,
        short playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint
    );
}

#endif //_GOMOKURULE_H_