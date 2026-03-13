#ifndef _SIMPLEAI_H_
#define _SIMPLEAI_H_

#include "../../shared/types/Position.h"

// Muc do DE - Greedy thuan
// Chi nhin 1 buoc: chon o co diem tan cong + phong thu cao nhat
Position getSimpleAIMove(int *board, int size, int winLen);

#endif // !_SIMPLEAI_H_