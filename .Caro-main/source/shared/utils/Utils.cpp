#include "../../../include/shared/utils/Utils.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#endif

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen()
{
#ifdef _WIN32
    system("pause");
#else
    std::cout << "Nhan Enter de tiep tuc...";
    std::cin.get();
#endif
}

std::string getCurrentTime()
{
    time_t now = time(nullptr);
    tm localTime;
#ifdef _WIN32
    localtime_s(&localTime, &now);
#else
    localtime_r(&now, &localTime);
#endif
    std::ostringstream ss;
    ss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

bool isInBounds(int row, int col, int size)
{
    return row >= 0 && row < size && col >= 0 && col < size;
}