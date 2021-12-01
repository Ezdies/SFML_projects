#include "Engine.h"
#include "Board.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 900), "TicTacToe");
    window.setFramerateLimit(60);

    Board board;
    fillBoard(board.box, board.boxes);

    while (window.isOpen()) {

        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            for (auto &box: board.boxes) {
                changeToX(box, event, window, board.counter);
            }
        }
        window.clear();
        board.printBoard(window);
        window.display();
    }
    return 0;
}
