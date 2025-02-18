#include "include/TMainHero.hpp"
#include "include/TView.hpp"
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

void TMainHero::Update(float speed, TView& View, std::vector<std::vector<char>>& Map) {
    float newX = X, newY = Y;
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
        newX -= speed;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
        HeroSprite.setTextureRect(RIGHT_RECT);
        CurrentFrame += 1;
        newX += speed;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
        HeroSprite.setTextureRect(UP_RECT);
        CurrentFrame += 1;
        newY -= speed;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
        HeroSprite.setTextureRect(DOWN_RECT);
        CurrentFrame += 1;
        newY += speed;
    }
    if (CanMoveTo(newX, newY, Map)){
        X = newX;
        Y = newY;
    } else {
        std::cout << "Движение запрещено!" << std::endl;
    }
    HeroSprite.setPosition(X, Y);
    View.getherocoordinateview(X, Y);
}

bool TMainHero::CanMoveTo(float newX, float newY, std::vector<std::vector<char>>& Map){
    int tileX1 = static_cast<int>(newX / 32);
    int tileY1 = static_cast<int>(newY / 32);
    int tileX2 = static_cast<int>((newX + 31) / 32);
    int tileY2 = static_cast<int>((newY + 31) / 32);

    if (tileX1 < 0 || tileY1 < 0 || tileY2 >= Map.size() || tileX2 >= Map[0].size()){
        return false;
    }

    char tile1 = Map[tileY1][tileX1];
    char tile2 = Map[tileY1][tileX2];
    char tile3 = Map[tileY2][tileX1];
    char tile4 = Map[tileY2][tileX2];

    if (tile1 == '0' || tile2 == '0' || tile3 == '0' || tile4 == '0'){
        return false;
    }

    if (tile1 == 's') Map[tileY1][tileX1] = ' ';
    if (tile2 == 's') Map[tileY1][tileX2] = ' ';
    if (tile3 == 's') Map[tileY2][tileX1] = ' ';
    if (tile4 == 's') Map[tileY2][tileX2] = ' ';

    return true;
}