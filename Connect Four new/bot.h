#ifndef BOT_H
#define BOT_H
#include <utility>
#include <vector>
#include "game.h"


class bot {
public:
    int getBestMove(std::vector<std::vector<Player>>& board, int depth);
    int min_max(std::vector<std::vector<Player>> &board, int depth, int alpha, int beta,bool forPlayer);

    static int evaluateMove(std::vector<std::vector<Player>> &board, int col, Player currentPlayer);

    static bool canWin(std::vector<std::vector<Player>> &board, int col, Player currentPlayer);

    static bool canBlock(std::vector<std::vector<Player>> &board, int col, Player currentPlayer);
};



#endif //BOT_H
