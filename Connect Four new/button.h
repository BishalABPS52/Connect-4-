#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class button: public sf::Drawable{
    sf::Sprite sprite;
    sf::Text text;
    sf::Vector2f pos_sprite = {0,0};
    sf::Vector2f pos_text = {0,0};
    bool isText = false;
    float scale = 1;
    float button_speed = 1;
    float dist = 0;
public:
    bool isEnlarged = false;
    button() = default;
    button(const sf::Texture&, sf::Vector2f, float);
    ~button() override = default;
    void setText(const std::string&, const sf::Font&,sf::Color color= sf::Color::White);
    void setPosition(sf::Vector2f);
    void enlarge(float);
    bool isClicked(sf::Vector2i) const;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void animate();
};



#endif //BUTTON_H

