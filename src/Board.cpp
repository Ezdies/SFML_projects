#include "Board.h"

Board::Board() = default;

Board::~Board() = default;

bool isLeftMouseButtonPressed(sf::Event &e) {
    if (e.type == sf::Event::MouseButtonPressed) {
        if (e.mouseButton.button == sf::Mouse::Left) {
            return true;
        }
    }
    return false;
}

void changeToX(sf::RectangleShape &box, sf::Event &e, sf::RenderWindow &window, int &counter) {
    if (box.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        if (isLeftMouseButtonPressed(e)) {
            if (counter % 2 == 0) {
                box.setFillColor(sf::Color::Blue);
            } else {
                box.setFillColor(sf::Color::Green);
            }
            counter++;
        }
    }
}

void fillBoard(sf::RectangleShape &box, std::vector<sf::RectangleShape> &boxes) {
    box.setSize(sf::Vector2f(295.f, 295.f));
    box.setFillColor(sf::Color::Red);

    const auto offset = 300.f;

    for (int i = 0; i < 9; i++) {
        if (i < 3) {
            box.setPosition(0, offset * (float) i);
            boxes.push_back(box);
        }
        if (i >= 3 && i <= 5) {
            box.setPosition(offset, offset * (float) (i - 3));
            boxes.push_back(box);
        }
        if (i > 5) {
            box.setPosition(2 * offset, offset * (float) (i - 6));
            boxes.push_back(box);
        }
    }
}

void Board::printBoard(sf::RenderWindow &window) {
    for (const auto &rect: Board::boxes) {
        window.draw(rect);
    }
}



