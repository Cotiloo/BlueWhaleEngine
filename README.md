# BlueWhale Engine

A high-performance chess engine written in C++ with UCI support, GUI integration, and web interface. Designed to compete with Stockfish and other top engines.

## Features

- **Strong AI**: Multi-threaded search with alpha-beta pruning and advanced evaluation
- **UCI Protocol**: Compatible with all standard chess GUIs (Arena, ChessTempo, etc.)
- **Web Interface**: Play directly in your browser
- **Desktop GUI**: Native chess board interface
- **Open Source**: GPL v3.0 licensed
- **Multi-threaded**: Parallelized search for maximum performance

## Quick Start

### Prerequisites
- C++17 or later
- CMake 3.15+
- Git

### Build

```bash
git clone https://github.com/Cotiloo/BlueWhaleEngine.git
cd BlueWhaleEngine
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Run

**UCI Mode (for chess GUIs):**
```bash
./BlueWhale
```

**Web Server:**
```bash
./BlueWhale --web --port 8080
```

## Project Structure

```
BlueWhaleEngine/
├── src/
│   ├── core/           # Core engine logic
│   ├── evaluation/      # Board evaluation
│   ├── search/          # Search algorithms
│   ├── uci/             # UCI protocol implementation
│   └── main.cpp         # Entry point
├── web/                 # Web interface
├── gui/                 # Desktop GUI (future)
├── tests/               # Unit tests
└── CMakeLists.txt       # Build configuration
```

## Architecture

### Board Representation
- Bitboards for efficient move generation and evaluation
- Move ordering for optimal alpha-beta pruning

### Search
- Iterative deepening with time management
- Alpha-beta pruning with transposition tables
- Quiescence search for tactical accuracy
- Multi-threading support

### Evaluation
- Material counting
- Positional evaluation (piece-square tables)
- King safety assessment
- Endgame evaluation tables

## Performance

Target: Competitive with top engines like Stockfish

## Contributing

Contributions are welcome! Please read our guidelines and submit pull requests.

## License

GNU General Public License v3.0 - See LICENSE file for details

## Author

BlueWhale Engine by Cotiloo
