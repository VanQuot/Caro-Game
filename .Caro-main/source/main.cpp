#include <cstdio>
#include <cstring>
#include "../include/bll/game/GameManager.h"
#include "../include/gui/GameRenderer.h"
#include "../include/dal/repositories/FileGameHistoryRepository.h"
#include "../include/shared/utils/Utils.h"

#define HISTORY_FILE "data/history.txt"

// ============================================================
//  Ham doc input
// ============================================================

// Doc mot so nguyen tu stdin.
// Tra ve -1 neu nhap sai dinh dang (tu dong xoa buffer loi).
static int readInt()
{
    int v;
    if (scanf("%d", &v) != 1)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        return -1;
    }
    return v;
}

// Doc ten nguoi choi, xu ly newline con lai trong buffer.
// Neu de trong thi dat ten mac dinh la "Player".
static void readName(char *buf, int maxLen, const char *prompt)
{
    printf("%s", prompt);
    int ch;
    while ((ch = getchar()) == '\n' || ch == '\r')
        ; // bo newline cu
    ungetc(ch, stdin);
    if (fgets(buf, maxLen, stdin))
    {
        int len = (int)strlen(buf);
        if (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
            buf[len - 1] = '\0';
    }
    if (strlen(buf) == 0)
        strcpy(buf, "Player");
}

// ============================================================
//  Vong lap mot van dau
// ============================================================
static void playGame(GameState &gs)
{
    clearScreen();

    while (!gs.gameOver)
    {
        renderBoard(gs);
        renderStatus(gs);

        // Luot AI (PvC)
        if (gs.mode == PVC && gs.currentTurn == 2)
        {
            printf("AI dang suy nghi...\n");
            doAITurn(gs);
            continue;
        }

        // Luot nguoi choi
        printf("Nhap hang va cot (vi du: 7 8): ");
        int row = readInt();
        int col = readInt();

        if (row == -1 || col == -1)
        {
            renderError("Nhap sai dinh dang. Vui long nhap 2 so nguyen.");
            continue;
        }

        row--;
        col--; // chuyen tu 1-based sang 0-based
        if (!makeMove(gs, row, col))
            renderError("Nuoc khong hop le (o da co quan hoac ngoai ban co).");
    }

    // Hien thi ket qua
    clearScreen();
    renderBoard(gs);
    renderResult(gs);

    saveGameResult(gs, HISTORY_FILE);
    printf("Da luu lich su van dau.\n\n");
    pauseScreen();
}

// ============================================================
//  Luong chon thong so truoc khi choi
// ============================================================
static bool setupGame(GameState &gs)
{
    // Chon loai game
    renderGameTypeMenu();
    int typeChoice = readInt();
    if (typeChoice != 1 && typeChoice != 2)
    {
        renderError("Lua chon khong hop le.");
        pauseScreen();
        return false;
    }
    GameType gtype = (typeChoice == 2) ? TICTACTOE : GOMOKU;

    // Chon che do choi
    renderModeMenu();
    int modeChoice = readInt();
    if (modeChoice != 1 && modeChoice != 2)
    {
        renderError("Lua chon khong hop le.");
        pauseScreen();
        return false;
    }
    GameMode gmode = (modeChoice == 2) ? PVC : PVP;

    // Chon do kho (chi khi PvC)
    Difficulty diff = EASY;
    if (gmode == PVC)
    {
        renderDifficultyMenu();
        int dChoice = readInt();
        if (dChoice == 2)
            diff = MEDIUM;
        else if (dChoice == 3)
            diff = HARD;
        else
            diff = EASY; // mac dinh De neu nhap sai
    }

    // Nhap ten nguoi choi
    char p1[32], p2[32];
    readName(p1, 32, "\nTen nguoi choi 1 (X): ");
    if (gmode == PVP)
        readName(p2, 32, "Ten nguoi choi 2 (O): ");
    else
        strcpy(p2, "AI");

    initGame(gs, gmode, gtype, diff, p1, p2);
    return true;
}

// ============================================================
//  Ham main
// ============================================================
int main()
{
    GameState gs;

    while (true)
    {
        clearScreen();
        renderMainMenu();

        int choice = readInt();

        switch (choice)
        {
        case 1:
            if (setupGame(gs))
                playGame(gs);
            break;

        case 2:
            clearScreen();
            showHistory(HISTORY_FILE);
            pauseScreen();
            break;

        case 3:
            printf("\nTam biet! Hen gap lai.\n");
            return 0;

        default:
            renderError("Vui long chon 1, 2 hoac 3.");
            pauseScreen();
            break;
        }
    }

    return 0;
}