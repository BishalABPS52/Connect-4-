#include "bot.h"

int bot::getBestMove(std::vector<std::vector<Player>>& board, int depth)
{
    std::vector<std::pair<int, int>> moveScores;
    for (int c = 0; c < COLS; c++)
    {
        if (board[0][c] == Player::None)
        {
            moveScores.emplace_back(c, evaluateMove(board, c, Player::Yellow));
        }
    }
    std::sort(moveScores.begin(), moveScores.end(), [](const auto& a, const auto& b)
    {
        return a.second > b.second;
    });

    int bestMove = -1;
    int maxEval = INT_MIN;

    for (const auto& [col, score] : moveScores)
    {
        int cur;
        for (cur = ROWS - 1; cur >= 0 && board[cur][col] != Player::None; cur--) {}

        board[cur][col] = Player::Yellow;
        int eval = min_max(board, depth - 1, INT_MIN, INT_MAX, false);
        board[cur][col] = Player::None;

        if (eval > maxEval)
        {
            maxEval = eval;
            bestMove = col;
        }
    }

    return bestMove;
}


int bot::min_max(std::vector<std::vector<Player>>& board, int depth, int alpha, int beta, bool forPlayer)
{
    if (checkWin(board, Player::Yellow))
    {
        return 2000 - depth;
    }
    if (checkWin(board, Player::Red))
    {
        return -2000 + depth;
    }
    if (depth == 0)
    {
        return 0;
    }

    std::vector<std::pair<int, int>> moveScores;
    for (int c = 0; c < COLS; c++)
    {
        if (board[0][c] == Player::None)
        {
            moveScores.emplace_back(c, evaluateMove(board, c, (forPlayer? Player::Yellow:Player::Red)));
        }
    }
    std::sort(moveScores.begin(), moveScores.end(), [](const auto& a, const auto& b)
    {
        return a.second > b.second;
    });

    if (forPlayer)
    {
        int maxEval = INT_MIN;
        for (const auto& [c,score]:moveScores)
        {
            int cur;
            for (cur = ROWS - 1; cur >= 0 && board[cur][c] != Player::None; cur--) {}

            board[cur][c] = Player::Yellow;
            int eval = min_max(board, depth - 1, alpha, beta, false);
            board[cur][c] = Player::None;

            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);

            if (beta <= alpha)
            {
                break; // Beta cut-off
            }
        }
        return maxEval;
    }
    else
    {
        int minEval = INT_MAX;
        for (const auto& [c,score]:moveScores)
        {
            int cur;
            for (cur = ROWS - 1; cur >= 0 && board[cur][c] != Player::None; cur--) {}

            board[cur][c] = Player::Red;
            int eval = min_max(board, depth - 1, alpha, beta, true);
            board[cur][c] = Player::None;

            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);

            if (beta <= alpha)
            {
                break; // Alpha cut-off
            }
        }
        return minEval;
    }
}


int bot::evaluateMove(std::vector<std::vector<Player>>& board, int col, Player currentPlayer)
{
    int score = 0;
    if (canWin(board, col, currentPlayer))
    {
        score += 1000;
    }

    Player opponent = (currentPlayer == Player::Yellow) ? Player::Red : Player::Yellow;
    if (canWin(board, col, opponent))
    {
        score += 500;
    }
    score = score + (50 * (3-std::abs(COLS/2 - col)));

    return score;
}


bool bot::canWin(std::vector<std::vector<Player>>& board, int col, Player currentPlayer)
{
    int row = -1;

    for (row = ROWS - 1; row >= 0 && board[row][col] != Player::None; row--) {}

    if (row < 0)
    {
        return false;
    }
    board[row][col] = currentPlayer;

    bool win = checkWin(board, currentPlayer);

    board[row][col] = Player::None;

    return win;
}

bool bot::canBlock(std::vector<std::vector<Player>>& board, int col, Player currentPlayer)
{

    Player opponent = (currentPlayer == Player::Yellow) ? Player::Red : Player::Yellow;

    return canWin(board, col, opponent);
}
