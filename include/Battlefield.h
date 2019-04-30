#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H
#include <string>
#include <SDL2/SDL.h>
#include <Robot.h>
#include <iostream>
class Battlefield
{
    public:
        Battlefield(const std::string &title , int width , int height);
        Battlefield();
        virtual ~Battlefield();
        inline bool isClosed() const { return close; };
        void poolEvent();
        void clear();

    private:
        bool init();
    private:
        std::string title;
        int width = 800;
        int height = 600;
        Robot* robot1;
        bool close;
        SDL_Window *battlefield = nullptr;
        SDL_Renderer *renderer = nullptr;
};

#endif // BATTLEFIELD_H
