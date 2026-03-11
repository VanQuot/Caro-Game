#include "../../include/bll/game/GameAction.h"

namespace GameAction
{
    void MakeMove(
        Board& board,
        short& moveCount,
        const Point& move,
        const short& playerValue
    )
    {
        board[move.row][move.col] = playerValue;
        moveCount++;
    }

    void UndoMove(
        Board& board,
        short& moveCount,
        const Point& move
    )
    {
        board[move.row][move.col] = 0;
        moveCount--;
    }

    static bool isValidPoint(short row, short col)
    {
        return !(row < 0 || col < 0 ||
                row >= Constants::BOARD_SIZE ||
                col >= Constants::BOARD_SIZE);
    }

    static void IteratePoints(
        const Board& board,
        const Point& move,
        const short player,
        std::vector<Point>& pointList,
        short rowDir,
        short colDir
    )
    {
        short row = move.row;
        short col = move.col;

        for (short i = 0; i < 4; i++)
        {
            row += rowDir;
            col += colDir;

            if (!isValidPoint(row, col)) break;

            if (board[row][col] == 0) continue;

            if (board[row][col] != player) break;

            pointList.push_back({row, col});

            if (pointList.size() == 3) break;
        }
    }

    static bool IsBlocked(
        const Board& board,
        short rowDir,
        short colDir,
        Point first,
        Point last
    )
    {
        short row = first.row - rowDir;
        short col = first.col - colDir;

        if (isValidPoint(row, col) && board[row][col] == 0)
            return false;

        row = last.row + rowDir;
        col = last.col + colDir;

        if (isValidPoint(row, col) && board[row][col] == 0)
            return false;

        return true;
    }

    std::vector<Point> GetWarningPoints(
        const Board& board,
        const Point& move,
        const short& player
    )
    {
        std::vector<Point> warningList;
        std::vector<Point> pointList;

        std::vector<Point> directions =
        {
            {-1,-1},{1,1},
            {-1,0},{1,0},
            {-1,1},{1,-1},
            {0,-1},{0,1}
        };

        for (size_t i = 0; i < directions.size(); i += 2)
        {
            pointList.clear();

            IteratePoints(board, move, player,
                        pointList,
                        directions[i].row,
                        directions[i].col);

            IteratePoints(board, move, player,
                        pointList,
                        directions[i+1].row,
                        directions[i+1].col);

            if (pointList.size() >= 3)
            {
                if (!IsBlocked(
                        board,
                        directions[i].row,
                        directions[i].col,
                        pointList.front(),
                        pointList.back()))
                {
                    warningList.insert(
                        warningList.end(),
                        pointList.begin(),
                        pointList.end());
                }
            }
        }

        return warningList;
    }
}
