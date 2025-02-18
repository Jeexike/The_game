#ifndef TMAP_H
#define TMAP_H

#include <string>
#include <vector>
#include "main.hpp"

class TMap {
private:
    int HEIGHT_MAP = 25;
    int WIDTH_MAP = 43;
    sf::Texture m_MapTexture;
    sf::Sprite m_MapSprite;
    std::vector<std::vector<char>> m_TileMap;

public:
    TMap();
    ~TMap();
    void DrawMap(sf::RenderWindow *Window);
    void GenerateRandomMap();
    std::vector<std::vector<char>>& GetMap();
};

#endif