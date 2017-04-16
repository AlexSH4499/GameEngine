//AABB-  Axis Aligned Bounding Box
#include"AABB.h"
#include "map.h"
#include "player.h"
#include<stdio.h>

//returns 0 or 1 if everything is OK
enum_bool AABBisIntersecting(AABB_strct *box1, AABB_strct *box2)
{
    //We need to test these properlyf
    enum_bool yOverlap ;
    enum_bool xOverlap ;
    enum_bool zOverlap ;

    if(box1->maxi.x > box2->position.x) xOverlap = false ;
    if(box1->maxi.y > box2->position.y) yOverlap = false ;
    if(box1->maxi.z > box2->position.z) zOverlap = false ;
    else
    {
        return -1;
    }

    //change back to && if necessary
    return xOverlap || yOverlap || zOverlap;
}

void initAABB(AABB_strct *AABB)
{
    mvector u = {0.0,0.0,0.0};

    AABB->maxi = u;
    AABB->position = u;
    AABB->velocity = u;
}
/*
void updateAABB(AABB_strct *AABB, char_strct *player, rectList_strct *rect)
{
    if(!AABB){ return ;}
    if(!player){return ;}
    if(!rect){return ;}

}
*/
//Creates AABB for each rectangle in list
void createAABB(rect_strct *rect)
{
  /*
    int i;
    AABB_strct box;

    box->velocity = {0.0,0.0,0.0};
    box.maxi->x = rect.pos.x + 1.0;
    box.maxi->y =  rect.pos.y + 1.0;
    box.maxi->z = rect.pos.z  + 1.0;

    box.position->x = rect.pos.x;
    box.position->y = rect.pos.y;
    box.position->z = rect.pos.z;
    */
}

void testAABB()
{
    puts("AABB Tests:\n\n");

    AABB_strct box,box2;

    box.maxi.x = 0.90f;
    box.maxi.y = 1.0f;
    box.maxi.z =-0.90f;

    box2.position.x = 1.0f;
    box2.position.y = 2.0f;
    box2.position.z =-1.0f;

    printf("Box 1:(%f,%f,%f)\n",box.maxi.x,box.maxi.y,box.maxi.z);
    printf("Box 2:(%f,%f,%f)\n\n",box2.position.x,box2.position.y,box2.position.z);

    enum_bool collides ;
    collides = AABBisIntersecting(&box,&box2);

    switch(collides)
    {
        case true:
            puts("Box 1 collided with Box 2!\n");
            break;

        case false:
            puts("No Collision with boxes...\n");
            break;
        case -1:
            puts("Error in AABBisIntersecting method!\n");
            break;

        default:
            puts("Our boolean enum failed... Oh oh! o.O\n");
            break;


    }

}
