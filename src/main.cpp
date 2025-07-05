#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <iostream>

int main() {
sf::RenderWindow window(
    sf::VideoMode(800, 780),
    "2048",
    sf::Style::Titlebar | sf::Style::Close
);

    window.setFramerateLimit(30);
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
           window.clear(sf::Color::White);
            sf::CircleShape circle;
            window.draw(circle);
            window.display();
        }
    }
}