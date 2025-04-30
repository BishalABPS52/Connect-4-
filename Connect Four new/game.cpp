#include "game.h"

void resetBoard(std::vector<std::vector<Player>> &board)
{
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            board[r][c] = Player::None;
        }
    }
}

bool checkWin(const std::vector<std::vector<Player>> &board, Player currentPlayer)
{
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            if (board[r][c] == currentPlayer)
            {
                // Check horizontally
                if (c + 3 < COLS &&
                        board[r][c + 1] == currentPlayer &&
                        board[r][c + 2] == currentPlayer &&
                        board[r][c + 3] == currentPlayer)
                {
                    return true;
                }
                // Check vertically
                if (r + 3 < ROWS &&
                        board[r + 1][c] == currentPlayer &&
                        board[r + 2][c] == currentPlayer &&
                        board[r + 3][c] == currentPlayer)
                {
                    return true;
                }
                // Check diagonal (top-left to bottom-right)
                if (r + 3 < ROWS && c + 3 < COLS &&
                        board[r + 1][c + 1] == currentPlayer &&
                        board[r + 2][c + 2] == currentPlayer &&
                        board[r + 3][c + 3] == currentPlayer)
                {
                    return true;
                }
                // Check diagonal (bottom-left to top-right)
                if (r - 3 >= 0 && c + 3 < COLS &&
                        board[r - 1][c + 1] == currentPlayer &&
                        board[r - 2][c + 2] == currentPlayer &&
                        board[r - 3][c + 3] == currentPlayer)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isBoardFull(const std::vector<std::vector<Player>> &board)
{
    for (const auto &row : board)
    {
        for (Player cell : row)
        {
            if (cell == Player::None)
            {
                return false;
            }
        }
    }
    return true;
}
