#include "button.h"

button::button(const sf::Texture &texture, const sf::Vector2f position, float scale) {
    sprite.setTexture(texture);
//    sprite.setOrigin(sprite.getLocalBounds().getSize().x/2,sprite.getLocalBounds().getSize().y/2);
    sprite.setPosition(position);
    sprite.setScale(scale,scale);
    this->scale = sprite.getScale().x;
    pos_sprite = sprite.getPosition();
}

void button::setText(const std::string& text, const sf::Font& font, const sf::Color color) {
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setFillColor(color);

    const sf::FloatRect text_bound = this->text.getLocalBounds();

    this->text.setOrigin(text_bound.width/2,text_bound.height/2);
    this->text.setPosition(sprite.getPosition().x+100,sprite.getPosition().y+20);
    pos_text = this->text.getPosition();

    isText = true;
}

void button::setPosition(const sf::Vector2f pos) {
    const sf::Vector2f diff = sprite.getPosition() - pos;
    sprite.setPosition(pos);
    if (isText) {
        text.move(diff);
    }
}

void button::enlarge(const float scale) {
    sprite.setScale(scale * this->scale * scale,scale * this->scale);
    if (isText) {
        this->text.setScale(scale,scale);
    }
    isEnlarged = scale > 1;
}

bool button::isClicked(const sf::Vector2i click_pos) const {
    return sprite.getGlobalBounds().contains(static_cast<float>(click_pos.x) ,static_cast<float>(click_pos.y));
}

void button::draw(sf::RenderTarget &target, const sf::RenderStates states) const {
    target.draw(sprite,states);
    if (isText) {
        target.draw(text,states);
    }
}

void button::animate() {
    dist += button_speed;
    const sf::Vector2f move = {0,dist};
    if (not isEnlarged) {
        sprite.setPosition(pos_sprite + move);
        if(isText) {
            text.setPosition(pos_text + move);
        }
    }
    if (dist>10) {
        button_speed = -1;
    }
    else if (dist<-10) {
        button_speed = 1;
    }
}





