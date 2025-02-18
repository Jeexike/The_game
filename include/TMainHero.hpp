#ifndef HEADER
#define HEADER

#include "main.hpp"

class TView;

class TMainHero{
    protected:
        float X, Y;
        sf::Texture HeroTexture;
        sf::Sprite HeroSprite;
    public:
        TMainHero(float aX, float aY);
        ~TMainHero();
        void Draw(sf::RenderWindow *Window);
        void Update(float speed, TView& view, std::vector<std::vector<char>>& Map);
        bool CanMoveTo(float newX, float newY, std::vector<std::vector<char>>& Map);
};

#endif