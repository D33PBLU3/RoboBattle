#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <Battlefield.h>

int main( int argc, char * argv[] )
{
    Battlefield battlefield("BattleField 1" , 800, 600);
    while(!battlefield.isClosed()){
        battlefield.poolEvent();
        battlefield.clear();
    }
    return 0;
}
