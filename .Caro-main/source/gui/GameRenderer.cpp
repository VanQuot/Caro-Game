#include "../../include/gui/GameRenderer.h"
#include <cstdio>

// Ky hieu hien thi
static char pieceChar(int p)
{
    if (p == PLAYER)
        return 'X';
    if (p == AI_PIECE)
        return 'O';
    return '.';
}

void renderBoard(const GameState &gs)
{
    int sz = gs.size;
    printf("\n");

    // Hang chi so cot
    if (sz == GOMOKU_SIZE)
    {
        printf("    ");
        for (int c = 0; c < sz; c++)
            printf("%2d", c + 1);
        printf("\n");
        printf("    ");
        for (int c = 0; c < sz; c++)
            printf("--");
        printf("\n");
    }
    else
    {
        printf("   ");
        for (int c = 0; c < sz; c++)
            printf(" %d", c + 1);
        printf("\n");
        printf("   ");
        for (int c = 0; c < sz; c++)
            printf("--");
        printf("\n");
    }

    // Cac hang ban co
    for (int r = 0; r < sz; r++)
    {
        printf("%2d |", r + 1);
        for (int c = 0; c < sz; c++)
        {
            printf(" %c", pieceChar(B(gs.board, r, c, sz)));
        }
        printf("\n");
    }
    printf("\n");
}

void renderStatus(const GameState &gs)
{
    if (gs.gameOver)
    {
        if (gs.winner == 3)
        {
            printf(">>> HOA! Khong co nguoi chien thang.\n");
        }
        else
        {
            const char *name = (gs.winner == 1) ? gs.player1Name : gs.player2Name;
            printf(">>> %s THANG! Chuc mung!\n", name);
        }
    }
    else
    {
        const char *name = (gs.currentTurn == 1) ? gs.player1Name : gs.player2Name;
        printf("Luot cua: %s (%c)\n", name, (gs.currentTurn == 1) ? 'X' : 'O');
    }
}

void renderMainMenu()
{
    printf("╔══════════════════════════╗\n");
    printf("║      GAME CARO / TTT     ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║  1. Choi moi             ║\n");
    printf("║  2. Xem lich su van dau  ║\n");
    printf("║  3. Thoat                ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Chon: ");
}

void renderGameTypeMenu()
{
    printf("\n--- Chon loai game ---\n");
    printf("1. Gomoku   (15x15, 5 lien tiep)\n");
    printf("2. TicTacToe (3x3,  3 lien tiep)\n");
    printf("Chon: ");
}

void renderModeMenu()
{
    printf("\n--- Che do choi ---\n");
    printf("1. PvP (2 nguoi)\n");
    printf("2. PvC (nguoi vs may)\n");
    printf("Chon: ");
}

void renderError(const char *msg)
{
    printf("[!] %s\n", msg);
}

void renderResult(const GameState &gs)
{
    printf("\n");
    if (gs.winner == 3)
    {
        printf("+=========================+\n");
        printf("|         HOA !!!         |\n");
        printf("+=========================+\n");
    }
    else
    {
        const char *name = (gs.winner == 1) ? gs.player1Name : gs.player2Name;
        printf("+================================+\n");
        printf("  CHIEN THANG: %s\n", name);
        printf("+================================+\n");
    }
    printf("\n");
}

void renderDifficultyMenu()
{
    printf("\n--- Do kho AI ---\n");
    printf("1. De     (Greedy)\n");
    printf("2. Vua    (Minimax)\n");
    printf("3. Kho    (Alpha-Beta)\n");
    printf("Chon: ");
}