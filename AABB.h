#ifndef AABB_H_INCLUDED
#define AABB_H_INCLUDED

#include"matrices.h"
#include"vectors.h"

typedef struct
{
    mvector position;
    mvector velocity;
    mvector maxi;
} AABB_strct;

/*
static inline float getWidth(box_strct *bx)
{
    if(bx == NULL)return -1.0f;

    return bx->position.x;
}

static inline float getHeight(box_strct *bx)
{
    if(bx == NULL)return -1.0f;

    return bx->position.y;
}

static inline float getDepth(box_strct *bx)
{
    if(bx == NULL)return -1.0f;

    return bx->position.z;
}
*/

enum_bool AABBisIntersecting(AABB_strct *box1, AABB_strct *box2);
void createAABB();
void updateAABB(AABB_strct *AABB);
void initAABB(AABB_strct *AABB);

//Debugging purposes
void testAABB();
#endif // AABB_H_INCLUDED
