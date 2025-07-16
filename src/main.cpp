#include <SFML/Graphics.hpp>

sf::RenderWindow CreateWindow() {
    sf::RenderWindow window(sf::VideoMode({768, 768}), "2048", sf::Style::Close | sf::Style::Titlebar);
    return window;
}
int main() {
    sf::RenderWindow window = CreateWindow();
    sf::Texture texture;
    if (!texture.loadFromFile("assets/gameBoard.png")) {
        return 1;
    }
    sf::Sprite sprite(texture);
    auto image = sf::Image{};
    if (!image.loadFromFile("assets/2048.png")) {
        return 1;
    }

    window.setIcon(image.getSize(), image.getPixelsPtr());
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }
}