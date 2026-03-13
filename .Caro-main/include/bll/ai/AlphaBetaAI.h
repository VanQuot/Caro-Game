#ifndef _ALPHABETAI_H_
#define _ALPHABETAI_H_

#include "../../shared/types/Position.h"

// Muc do KHO - Alpha-Beta Pruning depth 5
// Nhin truoc 5 buoc, co cat tinh -> nhanh hon Minimax ~10 lan
Position getAlphaBetaAIMove(int *board, int size, int winLen);

#endif // !_ALPHABETAI_H_