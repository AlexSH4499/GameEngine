#include <math.h>
#include <stddef.h>
#include "physics.h"

//#define NULL (0)
/*
    @param player This is the player struct to be compared
    @param stage This is the stage struct to be compared

*/


//method will require update since
//it bounds the character to the max & min of the box struct
//Which will cause trouble if using an array of boxes
void PSCollision(char_strct* player, AABB_strct* stage)
{
    if(player == NULL)
    {
        printf("No player in Collision Interactions method!\n");
        return;
    }

    if(stage == NULL)
    {
        printf("No stage in Collision Interactions method!\n");
        return;
    }

}
