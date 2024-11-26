
#include "draw.h"

void drawBoard(sf::RenderWindow &window, const std::vector<std::vector<Player>> &board,
               sf::Vector2f boardPosition, sf::CircleShape &currentBall)
{
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    cell.setFillColor(sf::Color::Blue);
    cell.setOutlineColor(sf::Color::Blue);
    cell.setOutlineThickness(5);

    sf::CircleShape hole(CELL_SIZE / 2.5f);
    hole.setFillColor(sf::Color::Black);

    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            cell.setPosition(boardPosition.x + c * CELL_SIZE, boardPosition.y + r * CELL_SIZE);
            window.draw(cell);

            hole.setPosition(boardPosition.x + c * CELL_SIZE + CELL_SIZE / 2 - hole.getRadius(),
                             boardPosition.y + r * CELL_SIZE + CELL_SIZE / 2 - hole.getRadius());
            window.draw(hole);

            if (board[r][c] != Player::None)
            {
                sf::CircleShape piece(CELL_SIZE / 2.5f - 5);
                piece.setFillColor(board[r][c] == Player::Red ? sf::Color::Red : sf::Color::Yellow);
                piece.setPosition(boardPosition.x + c * CELL_SIZE + CELL_SIZE / 2 - piece.getRadius(),
                                  boardPosition.y + r * CELL_SIZE + CELL_SIZE / 2 - piece.getRadius());
                window.draw(piece);
            }
        }
    }
}
