#ifndef ROBOT_H
#define ROBOT_H
#include <SDL2/SDL.h>

class Robot
{
    public:
        Robot();
        Robot(int x, int y, int width, int height, int color);
        virtual ~Robot();
        bool init();
        SDL_Rect* render(int x, int y, int width, int height, int color);
        SDL_Rect* getFigure();
    protected:
    private:
        int x;
        int y;
        int width;
        int height;
        SDL_Rect* figure = nullptr;

};

#endif // ROBOT_H
