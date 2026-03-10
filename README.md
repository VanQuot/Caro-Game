# caro-game

## 📁 Cấu trúc thư mục

```
caro-game/
├── .Caro-main/                          # Thư mục chính dự án
│   ├── source/                          # Mã nguồn
│   │   ├── main.cpp                     # Điểm vào chương trình
│   │   ├── bll/                         # Business Logic Layer
│   │   │   ├── ai/                      # Módun AI
│   │   │   │   ├── AlphaBetaAI.cpp
│   │   │   │   ├── MinimaxAI.cpp
│   │   │   │   ├── SimpleAI.cpp
│   │   │   │   └── BoardEvaluator.cpp
│   │   │   └── game/                    # Lôgic trò chơi
│   │   │       ├── GameManager.cpp
│   │   │       ├── GomokuRule.cpp
│   │   │       ├── TicTacToeRule.cpp
│   │   │       ├── Player.cpp
│   │   │       └── MoveValidator.cpp
│   │   ├── gui/                         # Giao diện người dùng
│   │   │   ├── MainWindow.cpp
│   │   │   ├── GameBoard.cpp
│   │   │   ├── GameRenderer.cpp
│   │   │   └── ControlPanel.cpp
│   │   ├── dal/                         # Data Access Layer
│   │   │   ├── repositories/            # Kho lưu trữ
│   │   │   │   ├── FileGameHistoryRepository.cpp
│   │   │   │   └── SqliteGameHistoryRepository.cpp
│   │   │   └── config/                  # Cấu hình
│   │   │       └── GameConfig.cpp
│   │   └── shared/                      # Mã chia sẻ
│   │       ├── types/
│   │       │   └── Position.cpp
│   │       └── utils/
│   │           └── utils.cpp
│   ├── include/                         # Tệp header
│   │   ├── bll/
│   │   │   ├── ai/
│   │   │   │   ├── AlphaBetaAI.h
│   │   │   │   ├── MinimaxAI.h
│   │   │   │   ├── SimpleAI.h
│   │   │   │   └── BoardEvaluator.h
│   │   │   └── game/
│   │   │       ├── GameManager.h
│   │   │       ├── GomokuRule.h
│   │   │       ├── TicTacToeRule.h
│   │   │       ├── Player.h
│   │   │       └── MoveValidator.h
│   │   ├── gui/
│   │   │   ├── MainWindow.h
│   │   │   ├── GameBoard.h
│   │   │   ├── GameRenderer.h
│   │   │   └── ControlPanel.h
│   │   ├── dal/
│   │   │   ├── entities/
│   │   │   │   ├── GameRecord.h
│   │   │   │   └── Move.h
│   │   │   ├── repositories/
│   │   │   │   ├── FileGameHistoryRepository.h
│   │   │   │   └── SqliteGameHistoryRepository.h
│   │   │   └── config/
│   │   │       └── GameConfig.h
│   │   └── shared/
│   │       ├── types/
│   │       │   ├── GameConstants.h
│   │       │   └── Position.h
│   │       └── utils/
│   │           └── utils.h
│   ├── tests/                           # Các bài kiểm thử
│   │   ├── bll/
│   │   │   ├── GameRuleTest.cpp
│   │   │   └── AITest.cpp
│   │   └── dal/
│   │       └── GameHistoryRepositoryTest.cpp
│   ├── assets/                          # Tài nguyên (hình ảnh, âm thanh,...)
│   ├── data/                            # Dữ liệu cấu hình
│   │   └── config.ini
│   ├── build/                           # Thư mục build (được tạo)
│   ├── bin/                             # Thư mục nhị phân (output)
│   └── CMakeLists.txt                   # Cấu hình CMake
├── README.md                            # Tài liệu này
├── LICENSE                              # Giấy phép
└── .gitignore                           # Cấu hình Git ignore
```

## 📋 Mô tả cấu trúc

- **source/**: Chứa toàn bộ mã nguồn C++
  - **bll/**: Business Logic Layer - Lôgic ứng dụng chính (AI, trò chơi)
  - **gui/**: Giao diện người dùng
  - **dal/**: Data Access Layer - Lớp truy cập dữ liệu
  - **shared/**: Các lớp, tiện ích chia sẻ

- **include/**: Các tệp header (.h) tương ứng với source

- **tests/**: Các bài kiểm thử đơn vị

- **data/**: Các tệp cấu hình và dữ liệu tĩnh

- **assets/**: Tài nguyên của ứng dụng (hình ảnh, âm thanh, v.v.)

- **build/**: Thư mục được tạo tự động khi compile

- **bin/**: Chứa các tệp nhị phân (executable) đã biên dịch