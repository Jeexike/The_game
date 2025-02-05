#ifndef TVIEW_H
#define TVIEW_H

#include "main.hpp"

class TView{
    private:
        sf::View view;
    public:
        TView();
        ~TView();
        void getherocoordinateview(float x, float y);
        void viewmap(float time);
        void changeview();
        void setView(sf::RenderWindow *Window);
};

#endif