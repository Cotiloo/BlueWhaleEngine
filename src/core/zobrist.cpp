#include "zobrist.h"
#include <random>

static u64 PIECE_HASH[64][6][2];
static u64 CASTLING_HASH[16];
static u64 EN_PASSANT_HASH[64];
static u64 SIDE_HASH;

void Zobrist::init() {
    std::mt19937_64 rng(0x9E3779B97F4A7C15ULL); // Fixed seed for reproducibility
    
    // Generate piece hashes
    for (int sq = 0; sq < 64; sq++) {
        for (int type = 0; type < 6; type++) {
            for (int color = 0; color < 2; color++) {
                PIECE_HASH[sq][type][color] = rng();
            }
        }
    }
    
    // Generate castling hashes
    for (int i = 0; i < 16; i++) {
        CASTLING_HASH[i] = rng();
    }
    
    // Generate en passant hashes
    for (int sq = 0; sq < 64; sq++) {
        EN_PASSANT_HASH[sq] = rng();
    }
    
    // Generate side to move hash
    SIDE_HASH = rng();
}

u64 Zobrist::piece(Square sq, PieceType type, Color color) {
    return PIECE_HASH[sq][type][color];
}

u64 Zobrist::castling(u8 rights) {
    return CASTLING_HASH[rights];
}

u64 Zobrist::enPassant(Square sq) {
    if (sq == SQUARE_NONE) return 0;
    return EN_PASSANT_HASH[sq];
}

u64 Zobrist::sideToMove() {
    return SIDE_HASH;
}
