cmake_minimum_required(VERSION 3.16)
project(CaroGame CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(ROOT_DIR ${CMAKE_SOURCE_DIR})

include_directories(${ROOT_DIR}/include)

set(SOURCES
    ${ROOT_DIR}/source/main.cpp

    # Shared
    ${ROOT_DIR}/source/shared/utils/Utils.cpp          # U hoa
    ${ROOT_DIR}/source/shared/types/Position.cpp

    # BLL - Game logic
    ${ROOT_DIR}/source/bll/game/GomokuRule.cpp
    ${ROOT_DIR}/source/bll/game/TicTacToeRule.cpp
    ${ROOT_DIR}/source/bll/game/GameManager.cpp
    ${ROOT_DIR}/source/bll/game/Player.cpp
    ${ROOT_DIR}/source/bll/game/MoveValidator.cpp

    # BLL - AI
    ${ROOT_DIR}/source/bll/ai/BoardEvaluator.cpp
    ${ROOT_DIR}/source/bll/ai/SimpleAI.cpp
    ${ROOT_DIR}/source/bll/ai/MinimaxAI.cpp
    ${ROOT_DIR}/source/bll/ai/AlphaBetaAI.cpp

    # GUI
    ${ROOT_DIR}/source/gui/GameRenderer.cpp
    ${ROOT_DIR}/source/gui/MainWindow.cpp
    ${ROOT_DIR}/source/gui/GameBoard.cpp
    ${ROOT_DIR}/source/gui/ControlPanel.cpp

    # DAL
    ${ROOT_DIR}/source/dal/repositories/FileGameHistoryRepository.cpp
    ${ROOT_DIR}/source/dal/repositories/SqliteGameHistoryRepository.cpp
    ${ROOT_DIR}/source/dal/config/GameConfig.cpp
)

add_executable(CaroGame ${SOURCES})

add_custom_command(TARGET CaroGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
            $<TARGET_FILE_DIR:CaroGame>/data
    COMMENT "Tao thu muc data/ cho file lich su"
)