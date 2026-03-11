#ifndef _GAMECONSTANTS_H_
#define _GAMECONSTANTS_H_
#include <filesystem>
#include <string>


namespace Constants
{
    

// Board configuration

// kích thước bàn cờ
const short BOARD_SIZE = 13;

// số quân liên tiếp để thắng (Gomoku = 5)
const short WIN_VALUE_COUNT = 5;


// Player definition
struct Player
{
    short value;   // ID player
    char symbol;   // ký hiệu trên bàn cờ
};

const Player PLAYER_ONE = {1, 'X'};
const Player PLAYER_TWO = {2, 'O'};


// Game mode
const short GAME_MODE_PVP = 0;   // Player vs Player
const short GAME_MODE_PVE = 1;   // Player vs AI


// Game type
const short GAME_TYPE_NORMAL = 0;
const short GAME_TYPE_RUSH   = 1;


//End Game
const short END_GAME_NONE    = 0;
const short END_GAME_WIN_ONE = 1;
const short END_GAME_WIN_TWO = 2;
const short END_GAME_DRAW    = 3;

}

#endif // !_GAMECONSTANTS_H_