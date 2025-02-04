#ifndef APPLICATION_TYPE_HEADER
#define APPLICATION_TYPE_HEADER

#include "main.hpp"
#include "TMapWidget.hpp"
#include "TMainHero.hpp"

namespace Lessons{
    class TApplication{
        protected:
            sf::RenderWindow *Window;
            TMapWidget *MapWidget;
            TMainHero *MainHero;
            sf::Clock clock;
        public:
            TApplication();
            ~TApplication();
            void Init();
            void Run();
            void End();
    };
}

#endif