#include "include/TMap.hpp"
#include <iostream>

TMap::TMap() : m_MapTexture()
{
    if (!m_MapTexture.loadFromFile("texture/map.png")) {
        std::cerr << "Ошибка загрузки текстуры!" << std::endl;
    }
    m_MapSprite.setTexture(m_MapTexture);
    m_TileMap = {
        "0000000000000000000000000000000000000000",
        "0                                      0",
        "0    s                                 0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0          s              s            0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                  s                   0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                        s             0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0000000000000000000000000000000000000000",
    };
}

TMap::~TMap()   {}

void TMap::DrawMap(sf::RenderWindow *Window)
{
    for (int i = 0; i < HEIGHT_MAP; i++)
    for (int j = 0; j < WIDTH_MAP; j++)
    {
        if (m_TileMap[i][j] == ' ') m_MapSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        if (m_TileMap[i][j] == 's') m_MapSprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
        if (m_TileMap[i][j] == '0') m_MapSprite.setTextureRect(sf::IntRect(64, 0, 32, 32));

        m_MapSprite.setPosition(j * 32, i * 32);
        Window->draw(m_MapSprite);
    }
}