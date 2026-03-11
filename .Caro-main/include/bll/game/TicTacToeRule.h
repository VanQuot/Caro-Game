#ifndef _TICTACTOERULE_H_
#define _TICTACTOERULE_H_
#pragma once

#include "GameAction.h"

namespace TicTacToeRule 
{
    const short NULL_VALUE = 0;
    const short DRAW_VALUE = 1;
    const short WIN_VALUE  = 2;

    short GetGameState(
        const GameAction::Board& board,
        short moveCount,
        const GameAction::Point& move,
        short playerValue
    );

    bool CheckDraw(
        const GameAction::Board& board,
        short moveCount
    );

    bool CheckWin(
        const GameAction::Board& board,
        const GameAction::Point& move,
        short playerValue
    );
}

#endif //_TICTACTOERULE_H_