#include <stdio.h>
#include "SDL.h"
#include "controls.h"

mvector keyListener()
{
    SDL_Event e;
    mvector u = {0.0,0.0,0.0};

    switch(e.key.keysym.sym)
    {

    case SDLK_UP:
//            u = {0.0,-1.0,0.0};
        return u;
        break;

    case SDLK_DOWN:
        //          u = {0.0,1.0,0.0};
        return u;
        break ;

    case SDLK_LEFT:
        //        u = {-1.0,0.0,0.0};
        return u;
        break ;

    case SDLK_RIGHT:
        //      u = {1.0,0.0,0.0};
        return u;
        break ;

    default:
        //     u = {0.0,0.0,0.0};
        return u;
        break;

    }
}

