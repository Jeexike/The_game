#ifndef XXX_HEADER
#define XXX_HEADER

#include "main.hpp"

class TMapWidget{
    protected:
        int X, Y, Width, Height;
        sf::Texture SomeTexture;
    public:
        TMapWidget(int aX, int aY, int aWidth, int aHeight);
        ~TMapWidget ();
        void Draw(sf::RenderWindow *Window);
};

#endif