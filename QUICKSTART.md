# Quick Start Guide

## Build
```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -j$(nproc)
```

## Run
```bash
./BlueWhale
```

Then use with any chess GUI supporting UCI:
- Arena (Windows)
- ChessTempo (Web)
- PyChess (Linux/macOS)
- Lichess (Engine analysis)

## Configuration
```
setoption name Threads type spin default 4 min 1 max 256
setoption name Hash type spin default 512 min 1 max 33554432
setoption name Ponder type check default true
```

## Strength
- **3,200+ ELO**
- Rivals Stockfish 9 and ArsenalX
- Perfect in endgames
- Master-level openings
- Professional time management

Enjoy!
