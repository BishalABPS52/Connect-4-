#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>


// Constants for the game
const int CELL_SIZE=100;
const int ROWS=6;
const int COLS=7;
const sf::Vector2f BALL_SIZE(80,80);


enum class Player { None, Red, Yellow };
enum class GameState { Menu, Playing, GameOver, Paused, help , transition};

// Function prototypes
void resetBoard(std::vector<std::vector<Player>> &board);
bool checkWin(const std::vector<std::vector<Player>> &board, Player currentPlayer);
bool isBoardFull(const std::vector<std::vector<Player>> &board);




#endif // GAME_H

