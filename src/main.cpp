#include <SFML/Graphics.hpp>
#include <iostream>

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
    texture.setSmooth(true);
    sf::Sprite sprite(texture);
    auto image = sf::Image{};
    if (!image.loadFromFile("assets/2048.png")) {
        return 1;
    }

    window.setIcon(image.getSize(), image.getPixelsPtr());
    window.setFramerateLimit(60);

    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    float scale = std::min(scaleX, scaleY);
    sprite.setScale(sf::Vector2f(scale, scale));

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