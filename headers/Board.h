#ifndef TEST_BOARD_H
#define TEST_BOARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Board {
public:
    sf::RectangleShape box;
    std::vector<sf::RectangleShape> boxes;
    int counter = 0;

    Board();

    ~Board();

    void printBoard(sf::RenderWindow &window);

};

void changeToX(sf::RectangleShape &box, sf::Event &e, sf::RenderWindow &window, int &counter);

void fillBoard(sf::RectangleShape &box, std::vector<sf::RectangleShape> &boxes);

bool isLeftMouseButtonPressed(sf::Event &e);

#endif //TEST_BOARD_H
