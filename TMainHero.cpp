#include "include/TMainHero.hpp"
#include "include/TMainHero.hpp"
#include <cmath>
#include <iostream>

int CurrentFrame = 0;

TMainHero::TMainHero(float aX, float aY) : X(aX), Y(aY), HeroTexture(), HeroSprite(){
    if (!HeroTexture.loadFromFile("texture/Hero.png")) {
        std::cerr << "Ошибка загрузки текстуры!" << std::endl;
    }

    HeroSprite.setTexture(HeroTexture);
    HeroSprite.setTextureRect(sf::IntRect(0, 192, 96, 96));
    HeroSprite.setPosition(X, Y);
}

TMainHero::~TMainHero()    {}

void TMainHero::Draw(sf::RenderWindow *Window){
    Window->draw(HeroSprite);
}

void TMainHero::Update(float speed) {
    ///CurrentFrame += 0.005 * speed;
    int maxFrames = 3;
    CurrentFrame = fmod(CurrentFrame, maxFrames);
    std::cout << CurrentFrame << std::endl;

    sf::IntRect STANDING_RECT(0, 192, 96, 96);
    sf::IntRect LEFT_RECT(96 * int(CurrentFrame), 96, 96, 96);
    sf::IntRect RIGHT_RECT(96 * int(CurrentFrame), 192, 96, 96);
    sf::IntRect UP_RECT(96 * int(CurrentFrame), 288, 96, 96);
    sf::IntRect DOWN_RECT(96 * int(CurrentFrame), 0, 96, 96);

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
        HeroSprite.setTextureRect(LEFT_RECT);
        CurrentFrame += 1;
        X -= speed;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
        HeroSprite.setTextureRect(RIGHT_RECT);
        CurrentFrame += 1;
        X += speed;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
        HeroSprite.setTextureRect(UP_RECT);
        CurrentFrame += 1;
        Y -= speed;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
        HeroSprite.setTextureRect(DOWN_RECT);
        CurrentFrame += 1;
        Y += speed;
    }
    HeroSprite.setPosition(X, Y);
}