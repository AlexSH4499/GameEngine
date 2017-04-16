#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "matrices.h"
#include "vectors.h"

typedef struct
{
    float modelView [4][4];
    float projection [4][4];
    float orientation [4][4];
    mvector position;

} cam_strct;

void returnCamera();

void initCamera(cam_strct * cam);

void moveCamera(cam_strct* cam, mvector vect);

void updateCam(cam_strct* cam);

void freeCamera(cam_strct* cam);

void setCameraPosition(cam_strct* cam,mvector vect);

void testCamera();

mvector moveCameraVect(cam_strct* cam, mvector vect);

#endif // CAMERA_H_INCLUDED
