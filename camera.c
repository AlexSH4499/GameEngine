#include "camera.h"

#include "matrices.h"

//mvector normGravVect;

void initCamera(cam_strct* cam)
{
    mvector vect = {0.0f,0.0f,0.0f};
    //initProjectMatrix((float*)cam->projection,1.3962634f,240.0f,0.01f,1000.0f);
    loadIdentity44(cam->orientation);
    loadIdentity44(cam->modelView);
    loadIdentity44(cam->projection);
    cam->position = vect;
    //normGravVect = vect;
}

void setCameraPosition(cam_strct* cam,mvector vect)
{
    if(!cam)
    {
        return;
    }
    cam->position = vect;
}

/*mvector moveCameraVect(cam_strct* cam, mvector vect, enum_bool free)
{
    //Verify this later as well
    mvector vect1 = mvector(cam->orientation[2][0],cam->orientation[2][1],cam->orientation[2][2]);

    if(!free)vect1 = normal(subtractVectors(vect1,dotProd(normGravVect,vect1))));

    return mvector((vect.y * vect1.x) + (vect.x*cam->orientation[0][0]));
}
*/
void moveCamera(cam_strct* cam,mvector vect)
{
    // if(!cam )return;
    //if(!vect)vect =(0.0,0.0,0.0);

    // cam->position = addVectors(cam->position,moveCameraVect(cam,vect,true));
}

void updateCam(cam_strct* cam)
{
    //Do update shennanigans
    if(cam == NULL)return;

//    memcpy(c->orientation,sizeof(matrix));
    // translateMatrix44((float*)cam->modelView);

    //We need to update the camera's pos & orientation


}

void useCamera(cam_strct *c)
{
    if(!c)return;

    /*gsMatrixMode(GS_PROJECTION);
    gsLoadIdentity();
    gsMultMatrix((float*)c->projection);

    gsMatrixMode(GS_MODELVIEW);
    gsMultMatrix((float*)c->modelview);
    */
}

/*
mvector box[]={(mvector){0.f,0.f,0.0f}
				(mvector){1.f,0.f,0.f},
				(mvector){0.f,1.f,0.f},
				(mvector){1.f,1.f,1.f}};
*/
void returnCamera(cam_strct *cam)
{
    if(cam == NULL)return;

    cam->position = (mvector)
    {
        0.0,0.0,0.0
    };//returns camera to initial place
    //cam->orientation = loadIdentity44();
}

void freeCamera(cam_strct* cam)
{
    free(&cam);
}

void testCamera()
{
    cam_strct cam;

    puts("Camera Tests:\n\n");

    initCamera(&cam);
    cam.position = (mvector)
    {
        0.0,0.0,0.0
    };

    printf("Orientation:\n");
    printMatrix((float*)cam.orientation,4);

    printf("Model View:\n");
    printMatrix((float*)cam.modelView,4);

    printf("Position: (%f, %f, %f)\n\n",
           cam.position.x, cam.position.y, cam.position.z);


}
