#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include <string>
#include <vector>

#include "../../shared/types/GameConstants.h"

// Move structure
struct Move
{
    short row;
    short col;
};

// GameState: lưu toàn bộ trạng thái của trận đấu
struct GameState
{
// danh sách nước đi
std::vector<Move> moveList;

// thông tin người chơi
std::string playerNameOne;
std::string playerNameTwo;

short playerAvatarOne = -1;
short playerAvatarTwo = -1;

// điểm số
short playerScoreOne = 0;
short playerScoreTwo = 0;

// thời gian
short playerTimeOne = 0;
short playerTimeTwo = 0;

short gameTime = 0;

// cấu hình game
short gameType = Constants::GAME_TYPE_NORMAL;
short gameMode = Constants::GAME_MODE_PVP;

short aiDifficulty = 0;

bool playerOneFirst = true;

// player hiện tại
short currentPlayer = Constants::PLAYER_ONE.value;

// trạng thái game
short gameEnd = Constants::END_GAME_NONE;

};

#endif