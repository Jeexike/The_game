#include "include/TView.hpp"

TView::TView()     {view.reset(sf::FloatRect(0, 0, 640, 480));}
TView::~TView()     {}
void TView::getherocoordinateview(float x, float y){
    float tempX = x; float tempY = y;
    if (x < 320) tempY = 320;
    if (y < 240) tempY = 240;
    if (y > 554) tempY = 554;
    view.setCenter(tempX, tempY);
}
void TView::viewmap(float time){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        view.move(0.1*time, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        view.move(0, 0.1*time);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        view.move(-0.1*time, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        view.move(0, -0.1*time);
    }
}
void TView::changeview(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
        view.zoom(1.0100f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        view.rotate(0.5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
        view.setSize(1000, 700);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        view.setSize(1920, 1080);
    }
}
void TView::setView(sf::RenderWindow *Window){
    Window->setView(view);
}