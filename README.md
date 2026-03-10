# 🎮 Caro Game - Trò Chơi Caro

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![C++](https://img.shields.io/badge/C%2B%2B-23-blue.svg)
![Platform](https://img.shields.io/badge/platform-Linux-green.svg)

## 📌 Giới Thiệu

**Caro Game** là một ứng dụng trò chơi Caro (TicTacToe/Gomoku) được phát triển bằng **C++23** với giao diện đồ họa thân thiện. Dự án hỗ trợ hai chế độ chơi chính:
- **Tic Tac Toe**: Trò chơi cơ bản trên bàn cờ 3x3
- **Gomoku**: Trò chơi nâng cao trên bàn cờ 15x15 với luật caro chuẩn

Dự án sử dụng kiến trúc **3-Layer** (BLL, DAL, GUI) với các thuật toán AI tiên tiến như **Minimax** và **Alpha-Beta Pruning** để cung cấp trải nghiệm chơi game thử thách.

---

## ✨ Tính Năng Chính

- 🤖 **AI Thông Minh**: 3 mức độ AI (Simple, Minimax, Alpha-Beta)
- 🎯 **2 Chế Độ Chơi**: Tic Tac Toe & Gomoku
- 💾 **Lưu & Tải Game**: Hỗ trợ 2 cách lưu (File & SQLite)
- 📊 **Thống Kê Game**: Lịch sử đầy đủ và phân tích hiệu năng
- 🎨 **Giao Diện Đẹp**: GUI hiện đại với bàn cờ tương tác
- ⚡ **Hiệu Năng Cao**: Tối ưu hóa nhân tạo với Alpha-Beta Pruning

---

## 🛠️ Yêu Cầu Hệ Thống

### Phụ Thuộc Bắt Buộc

| Thành Phần | Phiên Bản | Mục Đích |
|-----------|---------|---------|
| **g++** | 14+ | Biên dịch C++23 |
| **CMake** | 3.20+ | Build system |
| **C++ Standard** | C++23 | Ngôn ngữ lập trình |

### Phụ Thuộc Tùy Chọn

| Thư Viện | Mục Đích | Ghi Chú |
|---------|---------|--------|
| **Qt6** | Giao diện GUI | Nếu biên dịch với GUI |
| **SQLite3** | Lưu trữ dữ liệu | Cho chế độ lưu SQLite |

---

## 📁 Cấu Trúc Dự Án

```
caro-game/
├── .Caro-main/                          # Thư mục chính dự án
│   ├── source/                          # Mã nguồn
│   │   ├── main.cpp                     # Điểm vào chương trình
│   │   ├── bll/                         # Business Logic Layer
│   │   │   ├── ai/                      # Módun AI
│   │   │   │   ├── AlphaBetaAI.cpp      # Thuật toán Alpha-Beta Pruning
│   │   │   │   ├── MinimaxAI.cpp        # Thuật toán Minimax
│   │   │   │   ├── SimpleAI.cpp         # AI cơ bản
│   │   │   │   └── BoardEvaluator.cpp   # Đánh giá bàn cờ
│   │   │   └── game/                    # Lôgic trò chơi
│   │   │       ├── GameManager.cpp      # Quản lý trò chơi
│   │   │       ├── GomokuRule.cpp       # Luật Gomoku
│   │   │       ├── TicTacToeRule.cpp    # Luật Tic Tac Toe
│   │   │       ├── Player.cpp           # Lớp người chơi
│   │   │       └── MoveValidator.cpp    # Kiểm chứng nước đi
│   │   ├── gui/                         # Giao diện người dùng
│   │   │   ├── MainWindow.cpp           # Cửa sổ chính
│   │   │   ├── GameBoard.cpp            # Bàn cờ tương tác
│   │   │   ├── GameRenderer.cpp         # Vẽ bàn cờ
│   │   │   └── ControlPanel.cpp         # Bảng điều khiển
│   │   ├── dal/                         # Data Access Layer
│   │   │   ├── repositories/            # Kho lưu trữ
│   │   │   │   ├── FileGameHistoryRepository.cpp
│   │   │   │   └── SqliteGameHistoryRepository.cpp
│   │   │   └── config/                  # Cấu hình
│   │   │       └── GameConfig.cpp
│   │   └── shared/                      # Mã chia sẻ
│   │       ├── types/                   # Kiểu dữ liệu chung
│   │       │   └── Position.cpp
│   │       └── utils/                   # Tiện ích chung
│   │           └── utils.cpp
│   ├── include/                         # Tệp header (.h)
│   ├── tests/                           # Bài kiểm thử đơn vị
│   ├── assets/                          # Tài nguyên (hình ảnh, âm thanh)
│   ├── data/                            # Dữ liệu cấu hình
│   │   └── config.ini
│   ├── build/                           # Thư mục build (được tạo)
│   ├── bin/                             # Thư mục nhị phân (output)
│   └── CMakeLists.txt                   # Cấu hình CMake
├── README.md                            # Tài liệu này
├── LICENSE                              # Giấy phép MIT
└── .gitignore                           # Cấu hình Git ignore
```

---

## 🚀 Hướng Dẫn Cài Đặt

### 1. Clone Repository

```bash
git clone https://github.com/VanQuot/Caro-Game.git
cd caro-game
```

### 2. Cài Đặt Phụ Thuộc (Ubuntu 24.04)

```bash
# Cập nhật package manager
sudo apt update && sudo apt upgrade -y

# Cài đặt g++ 14 và CMake
sudo apt install -y g++-14 cmake build-essential

# (Tùy chọn) Cài Qt6 cho GUI
sudo apt install -y qt6-base-dev qt6-gui-dev

# (Tùy chọn) Cài SQLite3
sudo apt install -y sqlite3 libsqlite3-dev
```

### 3. Build Dự Án

```bash
cd .Caro-main

# Tạo thư mục build
mkdir -p build
cd build

# Cấu hình CMake
cmake .. -DCMAKE_CXX_COMPILER=g++-14 -DCMAKE_CXX_STANDARD=23

# Biên dịch
cmake --build . --config Release

# Build chạy xong, executable sẽ ở trong thư mục bin/
```

### 4. Chạy Ứng Dụng

```bash
cd ../bin
./caro-game
```

---

## 📖 Cách Sử Dụng

### Giao Diện Chính

1. **Khởi Động**: Chạy executable để mở giao diện chính
2. **Chọn Chế Độ**: Lựa chọn giữa Tic Tac Toe hoặc Gomoku
3. **Chọn Mức AI**: Chọn độ khó (Simple, Minimax, Alpha-Beta)
4. **Chơi Game**: 
   - Click vào ô trên bàn cờ để đặt quân
   - Máy tính sẽ tự động trả lên sau lượt của bạn
   - Trò chơi kết thúc khi có người thắng

### Ví Dụ Sử Dụng Lập Trình

```cpp
#include "bll/game/GameManager.h"
#include "bll/ai/AlphaBetaAI.h"

int main() {
    // Tạo game manager
    GameManager manager(GameMode::GOMOKU);
    
    // Tạo AI
    AlphaBetaAI ai(5);  // Độ sâu tìm kiếm = 5
    
    // Đặt nước
    Position move = ai.findBestMove(manager.getBoard());
    manager.makeMove(move);
    
    return 0;
}
```

---

## 🧪 Chạy Bài Kiểm Thử

```bash
cd .Caro-main/build

# Build tests
cmake --build . --target tests

# Chạy tests
ctest --verbose
```

### Các Bài Kiểm Thử Hiện Có

- **GameRuleTest**: Kiểm thử luật chơi Tic Tac Toe & Gomoku
- **AITest**: Kiểm thử thuật toán AI
- **GameHistoryRepositoryTest**: Kiểm thử lưu/tải game

---

## ❓ Câu Hỏi Thường Gặp (FAQ)

### Q: Làm sao để thay đổi mức độ khó của AI?
**A**: Trong lúc chọn chế độ chơi, bạn có thể chọn:
- **Simple AI**: Nước đi ngẫu nhiên (dễ)
- **Minimax**: Phân tích toàn bộ cây trò chơi (trung bình)
- **Alpha-Beta**: Minimax với cắt tỉa (khó)

### Q: Làm sao để lưu trò chơi của tôi?
**A**: Bảng điều khiển có nút **"Save Game"** để lưu trạng thái hiện tại. Chọn định dạng lưu (File hoặc SQLite) trong cài đặt.

### Q: Tôi có thể chơi với người chơi khác không?
**A**: Hiện tại hỗ trợ chơi với AI. Chế độ 2 người chơi sẽ được thêm vào các phiên bản tương lai.

### Q: Làm sao để thay đổi cấu hình?
**A**: Chỉnh sửa file `data/config.ini` hoặc sử dụng menu Settings trong ứng dụng.

---

## 🐛 Các Lỗi Đã Biết

| Lỗi | Nguyên Nhân | Giải Pháp |
|-----|-----------|---------|
| Không thể build | g++ 14 chưa được cài | Chạy: `sudo apt install g++-14` |
| AI chậm | Độ sâu tìm kiếm quá lớn | Giảm độ sâu hoặc sử dụng Alpha-Beta |
| Lỗi lưu trữ SQLite | SQLite3 chưa cài | Chạy: `sudo apt install libsqlite3-dev` |

---

## 🚧 Lộ Trình Phát Triển

- [x] Cơ bản AI (Simple, Minimax)
- [x] Alpha-Beta Pruning
- [x] Lưu trữ File & SQLite
- [ ] Chế độ 2 người chơi qua mạng
- [ ] Tích hợp OpenGL cho đồ họa nâng cao
- [ ] Phân tích game sâu hơn
- [ ] Machine Learning AI

---

## 📝 Lịch Sử Thay Đổi

### v1.0.0 (2026-03-10)
- ✅ Phát hành ban đầu
- ✅ Hỗ trợ Tic Tac Toe & Gomoku
- ✅ 3 mức AI
- ✅ Lưu trữ File & SQLite

---

## 🤝 Hướng Dẫn Đóng Góp

Chúng tôi rất hoan nghênh các đóng góp! Hãy:

1. **Fork repository** từ GitHub
2. **Tạo branch tính năng**: `git checkout -b feature/AmazingFeature`
3. **Commit thay đổi**: `git commit -m 'Add some AmazingFeature'`
4. **Push lên branch**: `git push origin feature/AmazingFeature`
5. **Mở Pull Request** và mô tả thay đổi chi tiết

### Điều Kiện Được Chấp Nhận

- ✅ Code tuân theo chuẩn C++23
- ✅ Có bài kiểm thử cho tính năng mới
- ✅ Cập nhật tài liệu nếu cần
- ✅ Không có `#include` không cần thiết
- ✅ Sử dụng naming convention: `camelCase` cho biến, `PascalCase` cho class

---

## 👥 Tác Giả & Cộng Tác Viên

- **VanQuot** - Tác giả chính - [GitHub](https://github.com/VanQuot)

---

## 📞 Hỗ Trợ

Nếu bạn gặp vấn đề:

- 📧 **Email**: [support@carogame.dev]
- 🐛 **Issues**: [GitHub Issues](https://github.com/VanQuot/Caro-Game/issues)
- 💬 **Discussions**: [GitHub Discussions](https://github.com/VanQuot/Caro-Game/discussions)

---

## 📜 Giấy Phép

Dự án này được cấp phép dưới **MIT License** - xem file [LICENSE](LICENSE) để biết chi tiết.

---

## 🎓 Tài Liệu Tham Khảo

- [C++ Standard Reference](https://en.cppreference.com/)
- [CMake Documentation](https://cmake.org/cmake/help/latest/)
- [Minimax Algorithm](https://en.wikipedia.org/wiki/Minimax)
- [Alpha-Beta Pruning](https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning)
- [Gomoku Rules](https://en.wikipedia.org/wiki/Gomoku)

---

## 📊 Thống Kê Dự Án

![Lines of Code](https://img.shields.io/badge/lines%20of%20code->5000-blue.svg)
![Tests](https://img.shields.io/badge/tests-passing-brightgreen.svg)
![Coverage](https://img.shields.io/badge/coverage-85%25-green.svg)

---

**Cảm ơn bạn đã sử dụng Caro Game! 🙌**