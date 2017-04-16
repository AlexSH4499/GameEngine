#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED


#include "vectors.h"
#include "matrices.h"
#include "AABB.h"
/*TypeDefs & Structs */


typedef struct
{

    float speed;
    float weight;

    mvector position;
    mvector maxi;

    AABB_strct hurtBox;

    enum_bool isOnMap;
    enum_bool canWallJump;
    enum_bool isMoving;

} char_strct;

/*---------------*/


/*Method Archetypes*/
void initPlayer(char_strct* character);
void movePlayer(char_strct* character,mvector *velocity);
void exitPlayer(char_strct* character);
void testPlayer(char_strct* character);
/*----------------*/
#endif // PLAYER_H_INCLUDED
