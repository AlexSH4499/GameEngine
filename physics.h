#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED

#include "AABB.h"
#include "player.h"

/*
    @param mass1 This is mass of first object
    @param mass2 This is mass of second object
    @param center This is the distance from the Gravity center
*/



void PSCollision(char_strct* player, AABB_strct* stage);

//void checkCrash(float x, float y);


#endif // PHYSICS_H_INCLUDED
