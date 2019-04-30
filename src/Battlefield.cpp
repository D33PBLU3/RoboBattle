#include "Battlefield.h"
Battlefield::Battlefield()
{
}

Battlefield::Battlefield(const std::string &title , int width, int height):
title(title), width(width), height(height)
{
    close = !init();
    robot1 = new Robot( width / 2 , height / 2 , 50 , 50 , 40 );
}

Battlefield::~Battlefield()
{
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(battlefield);
   SDL_Quit();
}

bool Battlefield::init(){
    bool initState = true;
    if(SDL_Init(SDL_INIT_VIDEO)!= 0){
        std::cerr << "Failed to initialize SDL. \n";
        initState = false;
    }
    battlefield = SDL_CreateWindow(title.c_str() , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED,width , height , 0);
    if(battlefield == nullptr){
        std::cerr << "Failed to create battlefield. \n";
        initState = false;
    }
    renderer = SDL_CreateRenderer(battlefield , -1 , SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        std::cerr << "Failed to create battlefield. \n";
        initState = false;
    }
    return initState;

 }
 void Battlefield::poolEvent(){
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            close = true;
            break;
        default:
            break;
        }
    }
 }
 void Battlefield::clear(){
    SDL_SetRenderDrawColor(renderer , 0 , 0, 200, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 200, 0 , 0, 255);
    SDL_RenderFillRect(renderer,robot1->getFigure());
    SDL_RenderPresent(renderer);
 }
