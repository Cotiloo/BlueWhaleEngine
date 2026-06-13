# Build Instructions

## Prerequisites
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.15 or later
- Git

## Linux/macOS

```bash
git clone https://github.com/Cotiloo/BlueWhaleEngine.git
cd BlueWhaleEngine
mkdir build
cd build
cmake ..
cmake --build . --config Release
./BlueWhale
```

## Windows (MSVC)

```bash
git clone https://github.com/Cotiloo/BlueWhaleEngine.git
cd BlueWhaleEngine
mkdir build
cd build
cmake ..
cmake --build . --config Release
.\Release\BlueWhale.exe
```

## Using with Chess GUIs

The engine implements the UCI (Universal Chess Interface) protocol, making it compatible with:

- **Arena** (Windows)
- **ChessTempo** (Web)
- **Lichess** (Web)
- **Chess.com** (Web)
- **PyChess** (Linux/Windows)

### Adding to Arena:
1. Engines > New Engine
2. Engine file: Select BlueWhale executable
3. Engine protocol: UCI
4. OK

### Adding to ChessTempo:
1. Settings > Engine
2. Engine path: /path/to/BlueWhale
3. Protocol: UCI

## Performance Optimization

For maximum performance:

```bash
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-O3 -march=native" ..
cmake --build . --config Release -j$(nproc)
```

This enables:
- O3 optimization level
- Native CPU instruction set
- Parallel compilation

## Next Steps

- [ ] Implement move generation for all pieces
- [ ] Complete board.makeMove() and board.unmakeMove()
- [ ] Implement Zobrist hashing
- [ ] Add piece-square tables
- [ ] Complete alpha-beta pruning
- [ ] Add time management
- [ ] Implement move ordering
- [ ] Add transposition table integration
- [ ] Create web interface
- [ ] Build desktop GUI
- [ ] Add endgame tables
- [ ] Optimize performance to reach Stockfish-level strength
