#ifndef _GAMERENDERER_H_
#define _GAMERENDERER_H_

#include "../bll/game/GameManager.h"

// ============================================================
//  GameRenderer.hpp
//  Chiu trach nhiem hien thi toan bo giao dien terminal:
//    - Ban co (ASCII)
//    - Trang thai van dau (luot di, ket qua)
//    - Cac man hinh menu
// ============================================================

// Ve ban co ra terminal (dung cho ca Gomoku 15x15 lan TicTacToe 3x3)
void renderBoard(const GameState &gs);

// Hien thi trang thai hien tai:
//   - Dang choi: "Luot cua: <ten> (X/O)"
//   - Ket thuc : ">>> <ten> THANG!" hoac ">>> HOA!"
void renderStatus(const GameState &gs);

// Man hinh menu chinh (Choi moi / Lich su / Thoat)
void renderMainMenu();

// Menu chon loai game (Gomoku / TicTacToe)
void renderGameTypeMenu();

// Menu chon che do choi (PvP / PvC)
void renderModeMenu();

// Menu chon do kho AI (De / Vua / Kho) - chi hien khi PvC
void renderDifficultyMenu();

// Hien thi thong bao loi ngan (1 dong)
void renderError(const char *msg);

// Hien thi banner ket qua sau khi van ket thuc
void renderResult(const GameState &gs);

#endif // !_GAMERENDERER_H_