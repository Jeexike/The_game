#include "include/TMapWidget.hpp"
#include <iostream>

TMapWidget::TMapWidget(int aX, int aY, int aWidth, int aHeight) : X(aX), Y(aY), Width(aWidth), Height(aHeight), SomeTexture() {
    if (!SomeTexture.loadFromFile("texture/grass10.jpg")) {
        std::cerr << "Ошибка загрузки текстуры!" << std::endl;
    }
}

TMapWidget::~TMapWidget()   {}

void TMapWidget::Draw(sf::RenderWindow *Window) {
    sf::Sprite SpriteStuff;
    SpriteStuff.setTexture(SomeTexture);
    SpriteStuff.setPosition(X, Y);
    float WidgetWidth = (float) Width / (float) SomeTexture.getSize().x;
    float WidgetHeight = (float) Height / (float) SomeTexture.getSize().y;
    SpriteStuff.setScale(WidgetWidth, WidgetHeight);

    Window->draw(SpriteStuff);
}