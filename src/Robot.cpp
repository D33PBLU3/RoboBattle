#include "Robot.h"

Robot::Robot()
{
    //ctor
}

Robot::~Robot()
{
    //dtor
}
Robot::Robot(int x, int y, int width, int height, int color){
    figure = new SDL_Rect();
    figure->h = height;
    figure->w = width;
    figure->x = x;
    figure->y = y;
}
SDL_Rect* Robot::render(int x, int y, int width, int height, int color){
    figure->h = height;
    figure->w = width;
    figure->x = x;
    figure->y = y;
    return figure;
}
SDL_Rect* Robot::getFigure(){
    return figure;
}
