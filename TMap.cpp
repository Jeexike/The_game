#include "include/TMap.hpp"
#include <iostream>
#include <ctime>

TMap::TMap() : m_MapTexture()
{
    if (!m_MapTexture.loadFromFile("texture/map.png")) {
        std::cerr << "Ошибка загрузки текстуры!" << std::endl;
    }
    m_MapSprite.setTexture(m_MapTexture);
    GenerateRandomMap();
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

void TMap::GenerateRandomMap(){
    srand(time(nullptr));

    m_TileMap.resize(HEIGHT_MAP, std::vector<char>(WIDTH_MAP, ' '));

    for (int i = 0; i < HEIGHT_MAP; i++){
        for (int j = 0; j < WIDTH_MAP; j++){
            if (i == 0 || i == HEIGHT_MAP - 1 || j == 0 || j == WIDTH_MAP - 1){
                m_TileMap[i][j] = '0';
            } else if (rand() % 100 < 5) {
                m_TileMap[i][j] = '0';
            } else if (rand() % 100 < 3) {
                m_TileMap[i][j] = 's';
            } else {
                m_TileMap[i][j] = ' ';
            }
        }
    }

    m_TileMap[1][1] = ' ';
}

std::vector<std::vector<char>>& TMap::GetMap() {return m_TileMap;}