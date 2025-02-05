#ifndef TMAP_H
#define TMAP_H

#include <string>
#include <array>
#include "main.hpp"

class TMap {
private:
    static constexpr int HEIGHT_MAP = 25;
    static constexpr int WIDTH_MAP = 40;
    sf::Texture m_MapTexture;
    sf::Sprite m_MapSprite;
    std::array<std::string, HEIGHT_MAP> m_TileMap;

public:
    TMap();
    ~TMap();
    void DrawMap(sf::RenderWindow *Window);
};

#endif