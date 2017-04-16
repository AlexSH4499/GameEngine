#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define FRAME_CAP 60

#include <stdio.h>

#include <stdlib.h>

#include "SDL.h"
#include "SDL_image.h"

#include "map.h"
#include "AABB.h"
#include "matrices.h"
#include "camera.h"
#include "physics.h"
#include "player.h"

typedef struct dot{
     int DOT_WIDTH ;
     int DOT_HEIGHT ;
    int DOT_VEL ;
   int mPosX , mPosY;
}dot_struct;


int getDotPosX(dot_struct* d);
int getDotPosY(dot_struct* d);

void SetupWindow();
void move(dot_struct* d);
//void handleEvent(SDL_Event& e);
void render(int camX , int camY);
void Initialize();
//void render();
void update();
void cleanUp();
void run();
void Pause();
void close();
void cameraSetup();
int loadImage();
int loadMedia();
void debugging();


double Interpolate(double g , double c , double t);

#endif // MAIN_H_INCLUDED
