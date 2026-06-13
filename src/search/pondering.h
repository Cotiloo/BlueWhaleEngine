#ifndef BLUEWHALE_PONDERING_H
#define BLUEWHALE_PONDERING_H

#include "../core/board.h"
#include "search_advanced.h"
#include <thread>
#include <atomic>
#include <mutex>

// Pondering (thinking during opponent's time)
class PonderingEngine {
public:
    explicit PonderingEngine(Board& board, SearchEngine& engine);
    ~PonderingEngine();

    // Start pondering with expected opponent move
    void startPondering(Move expectedMove);
    
    // Stop pondering (opponent made their move)
    void stopPondering();
    
    // Update ponder move if opponent makes different move
    void updatePonderMove(Move actualMove);
    
    // Get pondered result
    Move getPonderedMove() const { return m_ponderedMove; }
    int getDepthReached() const { return m_depthReached; }

private:
    Board& m_board;
    SearchEngine& m_engine;
    
    std::thread m_ponderThread;
    std::atomic<bool> m_isPondering;
    std::atomic<bool> m_stopRequested;
    
    Move m_expectedMove;
    Move m_ponderedMove;
    int m_depthReached = 0;
    
    std::mutex m_moveMutex;
    
    // Worker function
    void ponderWorker();
};

#endif // BLUEWHALE_PONDERING_H
