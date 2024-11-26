
#ifndef DRAW_H
#define DRAW_H

#include <SFML/Graphics.hpp>
#include "game.h"

// Drawing functions
void drawBoard(sf::RenderWindow &window, const std::vector<std::vector<Player>> &board,
               sf::Vector2f boardPosition, sf::CircleShape &currentBall);


#endif // DRAW_H
