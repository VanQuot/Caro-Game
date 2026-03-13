#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>

void clearScreen();
void pauseScreen();
std::string getCurrentTime();
bool isInBounds(int row, int col, int size);

#endif // !_UTILS_H_