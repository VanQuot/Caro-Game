#include "../../../include/dal/repositories/FileGameHistoryRepository.h"
#include "../../../include/shared/utils/Utils.h"
#include <fstream>
#include <cstdio>
#include <cstring>

// ============================================================
//  Hang so noi bo
// ============================================================
static const char *SEPARATOR = "===========================================";
#define LINES_PER_PAGE 40 // so dong hien thi truoc khi hoi tiep tuc

// ============================================================
//  saveGameResult
// ============================================================
void saveGameResult(const GameState &gs, const std::string &filePath)
{
    FILE *f = fopen(filePath.c_str(), "a"); // append
    if (!f)
    {
        printf("[!] Khong the mo file luu lich su: %s\n", filePath.c_str());
        return;
    }

    // Xac dinh do kho
    const char *diffStr = "";
    if (gs.mode == PVC)
    {
        if (gs.difficulty == EASY)
            diffStr = "De (Greedy)";
        else if (gs.difficulty == MEDIUM)
            diffStr = "Trung binh (Minimax)";
        else
            diffStr = "Kho (Alpha-Beta)";
    }

    // Xac dinh ket qua
    char resultStr[64];
    if (gs.winner == 3)
    {
        strcpy(resultStr, "Hoa");
    }
    else
    {
        const char *winner = (gs.winner == 1) ? gs.player1Name : gs.player2Name;
        snprintf(resultStr, sizeof(resultStr), "%s thang!", winner);
    }

    fprintf(f, "%s\n", SEPARATOR);
    fprintf(f, "Thoi gian : %s\n", getCurrentTime().c_str());
    fprintf(f, "Loai game : %s\n",
            gs.type == GOMOKU ? "Gomoku (15x15)" : "TicTacToe (3x3)");
    fprintf(f, "Che do    : %s\n", gs.mode == PVP ? "PvP" : "PvC");
    if (gs.mode == PVC)
        fprintf(f, "Do kho AI : %s\n", diffStr);
    fprintf(f, "Nguoi choi: %s vs %s\n", gs.player1Name, gs.player2Name);
    fprintf(f, "Ket qua   : %s\n", resultStr);
    fprintf(f, "%s\n\n", SEPARATOR);

    fclose(f);
}

// ============================================================
//  showHistory
// ============================================================
void showHistory(const std::string &filePath)
{
    FILE *f = fopen(filePath.c_str(), "r");
    if (!f)
    {
        printf("\nChua co lich su van dau nao.\n");
        return;
    }

    int total = countGames(filePath);
    printf("\n===== LICH SU VAN DAU (%d van) =====\n\n", total);

    char line[256];
    int lineCount = 0;

    while (fgets(line, sizeof(line), f))
    {
        printf("%s", line);
        lineCount++;

        // Phan trang: cu LINES_PER_PAGE dong hoi nguoi dung
        if (lineCount >= LINES_PER_PAGE)
        {
            printf("\n-- Nhan Enter de xem tiep, 'q' + Enter de thoat --\n");
            char c = (char)getchar();
            if (c == 'q' || c == 'Q')
                break;
            lineCount = 0;
        }
    }

    fclose(f);
    printf("\n--- Het lich su ---\n");
}

// ============================================================
//  clearHistory
// ============================================================
bool clearHistory(const std::string &filePath)
{
    FILE *f = fopen(filePath.c_str(), "w"); // ghi de = xoa noi dung
    if (!f)
    {
        printf("[!] Khong the xoa lich su: %s\n", filePath.c_str());
        return false;
    }
    fclose(f);
    printf("Da xoa toan bo lich su.\n");
    return true;
}

// ============================================================
//  countGames
// ============================================================
int countGames(const std::string &filePath)
{
    FILE *f = fopen(filePath.c_str(), "r");
    if (!f)
        return 0;

    int count = 0;
    char line[256];
    // Moi ban ghi co "Ket qua" -> dem dong chua tu khoa nay
    while (fgets(line, sizeof(line), f))
    {
        if (strncmp(line, "Ket qua", 7) == 0)
            count++;
    }

    fclose(f);
    return count;
}