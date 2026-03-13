#ifndef _FILEGAMEHISTORYREPOSITORY_H_
#define _FILEGAMEHISTORYREPOSITORY_H_

#include "../../bll/game/GameManager.h"
#include <string>

// ============================================================
//  FileGameHistoryRepository.hpp
//  Chiu trach nhiem doc/ghi lich su van dau vao file .txt
//
//  Format moi ban ghi trong file:
//  ===========================================
//  Thoi gian : 2024-01-15 20:30:00
//  Loai game : Gomoku (15x15)
//  Che do    : PvC
//  Do kho AI : Kho
//  Nguoi choi: Quoc vs AI
//  Ket qua   : Quoc thang!
//  ===========================================
// ============================================================

// Luu ket qua van dau hien tai vao cuoi file (append).
// Tu dong tao file neu chua ton tai.
void saveGameResult(const GameState &gs, const std::string &filePath);

// Doc va in toan bo lich su tu file ra terminal.
// Hien thi thong bao neu file trong hoac chua ton tai.
void showHistory(const std::string &filePath);

// Xoa toan bo lich su (ghi de file rong).
// Tra ve true neu thanh cong.
bool clearHistory(const std::string &filePath);

// Dem tong so van da luu trong file.
int countGames(const std::string &filePath);

#endif // !_FILEGAMEHISTORYREPOSITORY_H_