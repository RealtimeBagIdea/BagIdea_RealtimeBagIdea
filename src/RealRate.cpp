#include "RealRate.h"
#include <SDL.h>

RealRate::RealRate()
{
    startTicks = 0;
}

void RealRate::start()
{
    startTicks = SDL_GetTicks();
}

void RealRate::frameRate(int rate)
{
    if( ( get_ticks() < 1000 / rate ) )
    {
        SDL_Delay( ( 1000 / rate ) - get_ticks() );
    }
}

int RealRate::get_ticks()
{
    return SDL_GetTicks() - startTicks;
}
