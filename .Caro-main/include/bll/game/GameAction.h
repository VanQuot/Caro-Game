#ifndef _GAME_ACTION_H_
#define _GAME_ACTION_H_

#include <vector>

#include "Constants.h"
#include "GameState.h"

namespace GameAction 
{

// Point structure
struct Point 
{
    short row;
    short col;
};

// Board type
using Board = std::vector<std::vector<short>>;

// Đặt quân
void MakeMove(
    Board& board,
    short& moveCount,
    const Point& move,
    const short& playerValue
);

// Undo nước đi
void UndoMove(
    Board& board,
    short& moveCount,
    const Point& move
);
// Lấy các điểm cảnh báo (4 quân liên tiếp)
std::vector<Point> GetWarningPoints(
    const Board& board,
    const Point& move,
    const short& player
);
}

#endif