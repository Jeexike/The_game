#include "include/TApplication.hpp"
#include "include/TMapWidget.hpp"
#include "include/TMainHero.hpp"
#include <iostream>

namespace Lessons{
    TApplication::TApplication():
        Window(nullptr), MapWidget(nullptr)  {}
    
    TApplication::~TApplication()   {}

    void TApplication::Init(){
        if (Window == nullptr){
            Window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "4X TBS Lessons");
            MapWidget = new TMapWidget(0, 0, 1920, 1080);
            MainHero = new TMainHero(50, 25);
        }
    }

    void TApplication::Run(){
        while (Window->isOpen()){
            sf::Event event;
            while (Window->pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    Window->close();
            }
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time/3200;
            std::cout << time << "\n";
            MainHero->Update(time);
            Window->clear(sf::Color::Black);
            MapWidget->Draw(Window);
            MainHero->Draw(Window);
            Window->display();
        }    
    }

    void TApplication::End(){
        if (Window != nullptr){
            delete Window;
            Window = nullptr;
        }
        if (MapWidget != nullptr){
            delete MapWidget;
            MapWidget = nullptr;
        }
    }
}