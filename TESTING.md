# Testing Guide

## Unit Tests

Run the test suite:
```bash
cd build
ctest
```

## Perft Testing

Perft (performance test) counts the number of leaf nodes at a given depth.

### Starting Position
```
position startpos
go perft 1
```

Expected results:
- Perft 1: 20
- Perft 2: 400
- Perft 3: 5,362
- Perft 4: 71,864
- Perft 5: 809,122
- Perft 6: 9,132,484

## Integration Testing

### Test Positions

**Mate in 2**
```
position fen r1bqkb1r/pppp1ppp/2n2n2/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R w KQkq - 0 1
```

**Endgame Position**
```
position fen 8/8/8/4k3/3K4/8/8/8 w - - 0 1
```

**Complex Middlegame**
```
position fen r1bqkbnr/pppp1ppp/2n5/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R w KQkq - 2 3
```

## Performance Benchmarking

Measure nodes per second:
```bash
position startpos
go depth 10
```

Target: **1,000,000+ NPS** (nodes per second)

## Engine Analysis

Use any UCI-compatible GUI to analyze positions:

### Recommended Tools
- **Arena**: Free, Windows
- **ChessTempo**: Web-based
- **PyChess**: Linux/macOS
- **Lichess**: Online with engine analysis

### Analysis Tips
1. Analyze starting position to depth 20+
2. Compare with other engines (Stockfish, Komodo)
3. Look for tactical oversights
4. Check endgame accuracy

## Debugging

### Enable Logging
Add debug output in search.cpp:
```cpp
if (depth <= 2) {
    std::cerr << "Depth: " << depth << " Score: " << score << std::endl;
}
```

### Test Specific Positions
```bash
# Load a position
position fen <fen_string>

# Analyze
go depth 15

# Try different moves
position fen <fen_string> moves e2e4
```

## Regression Testing

Create a test suite of positions with known best moves:

```cpp
struct TestPosition {
    std::string fen;
    std::string expectedMove;
    int minDepth;
};

// Run tests and verify engine finds expected move
```

## Performance Profiling

### Linux with perf
```bash
perf record -g ./BlueWhale < test_commands.txt
perf report
```

### macOS with Instruments
```bash
instruments -t "System Trace" -l 30000 ./BlueWhale
```

### Profile Specific Functions
Add timing to search.cpp:
```cpp
auto start = std::chrono::high_resolution_clock::now();
// ... search code ...
auto end = std::chrono::high_resolution_clock::now();
auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
std::cerr << "Search took " << ms << "ms" << std::endl;
```

## Test Script Example

```bash
#!/bin/bash

echo "Testing BlueWhale Chess Engine"
echo "=============================="

# Test move generation
echo "Test 1: Move Generation"
echo "position startpos" > test_input.txt
echo "go perft 3" >> test_input.txt
./BlueWhale < test_input.txt

# Test mate position
echo -e "\nTest 2: Mate Detection"
echo "position fen r1bqkb1r/pppp1ppp/2n2n2/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R w KQkq - 0 1" > test_input.txt
echo "go depth 5" >> test_input.txt
./BlueWhale < test_input.txt

rm test_input.txt
```
