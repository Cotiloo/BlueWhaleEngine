#ifndef BLUEWHALE_EVALUATION_ADVANCED_H
#define BLUEWHALE_EVALUATION_ADVANCED_H

#include "../core/types.h"
#include "../core/board.h"
#include "eval.h"

class AdvancedEvaluator {
public:
    explicit AdvancedEvaluator(const Board& board);

    // Main evaluation function
    Score evaluate();

private:
    const Board& m_board;

    // Evaluation components
    Score evaluateMaterial();
    Score evaluatePieceSquareTables();
    Score evaluateKingSafety();
    Score evaluatePawnStructure();
    Score evaluatePassedPawns();
    Score evaluatePieceActivity();
    Score evaluateMobility();
    Score evaluateThreats();
    
    // Helper functions
    bool isKingExposed(Color color);
    int countAttackers(Square sq, Color attackerColor);
    int getKingShield(Color color);
};

#endif // BLUEWHALE_EVALUATION_ADVANCED_H
