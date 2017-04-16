#include <time.h>
#include <stddef.h>

#include "main.h"
#include "camera.h"
#include "controls.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400
#define LEVEL_WIDTH 600
#define LEVEL_HEIGHT 400
char_strct player;
cam_strct cam;

SDL_Window *win ;
SDL_Surface *screen;
SDL_Surface *image;

SDL_Renderer* renderer = NULL;

SDL_Texture* texture = NULL;

SDL_Texture* loadTexture(char* path);

SDL_Rect gridToUse[256] ;

dot_struct* dot;

dot_struct initDot()
{
    dot_struct dot;

    dot.DOT_HEIGHT = 10;
    dot.DOT_WIDTH = 10;

    dot.mPosX = 0;
    dot.mPosY = 0;

    dot.mVelX = 0;
    dot.mVelY = 0;

      //Set collision box dimension
      dot.collider.x=dot.mPosX ;
      dot.collider.y=dot.mPosY ;
    dot.collider.w = dot.DOT_WIDTH;
    dot.collider.h = dot.DOT_HEIGHT;

    return dot;
}
/*
void moveDot(SDL_Rect &wall)
{

    dot.mPosX += dot.mVelX;
    dot.collider.x = dot.mPosX;

    if( ( dot.mPosX < 0 ) || ( dot.mPosX + dot.DOT_WIDTH > SCREEN_WIDTH ) || checkCollision( dot.collider, wall ) )
    {
        //Move back
        dot.mPosX -= dot.mVelX;
        dot.collider.x = dot.mPosX;
    }

        dot.mPosY += dot.mVelY;
    dot.collider.y = dot.mPosY;

    if( ( dot.mPosY < 0 ) || ( dot.mPosY + dot.DOT_WIDTH > SCREEN_HEIGHT ) || checkCollision( dot.collider, wall ) )
    {
        //Move back
        dot.mPosY -= dot.mVelY;
        dot.collider.y = dot.mPosY;
    }
}
*/

void renderDot(dot_struct* d , SDL_Texture* texture)
{
    SDL_Rect proxy ;
  //  SDL_Rect *ptr = &proxy;
  /*  proxy.x = d.collider.x;
    proxy.y = d.collider.y;
    proxy.w = d.collider.w;
    proxy.h = d.collider.h;
*/

    proxy.x = 50;
    proxy.y = 60;
    proxy.w = 960;
    proxy.h =614;
    render(d->mPosX,d->mPosY, d->collider , texture);

}
int checkCollision(SDL_Rect a, SDL_Rect b)
{
     //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return 0;
    }

    if( topA >= bottomB )
    {
        return 0;
    }

    if( rightA <= leftB )
    {
        return 0;
    }

    if( leftA >= rightB )
    {
        return 0;
    }

    //If none of the sides from A are outside B
    return 1;
}

//Remember to allocate this to memory
SDL_Rect* createGrid()
{
    SDL_Rect grid[256];
    int i,j;

    for(i = 0; i < 256; i++)
    {
        for(j = 0; j < 256;j++)
        {
            grid[i].x =  i;
            grid[i].y =  j;
            grid[i].w =  3;
            grid[i].h =  2;
        }
    }
    return grid;
}
/*
double keyboardInput( SDL_Event &e )
{
    switch(e.key.keysym.sym)
    {
        case SDLK_UP:
            //Do something
            break;

        case SDLK_DOWN:
            //Do something
            break;

        case SDLK_LEFT:
            //Do something
            break;

        case SDLK_RIGHT:
            //Do something
            break;

        default:
            break;
    }

}
*/
void debugging()
{
    // int i;

    testAABB();
    testMatrices();
    testCamera();
    testPlayer(&player);
    loadImage();
    /*while(i!=9)
    {
        movePlayer(player,keyListener());
        printf("Player position: (%f, %f, %f)\n",player.position.x,player.position.y,player.position.z);
        scanf("%d", &i);
    }*/
}
/*
void move(dot_struct *d)
{
    d->mPosX += d->DOT_VEL ;

    //If the dot went too far to the left or right
    if( ( d->mPosX < 0 ) || ( d->mPosX + d->DOT_WIDTH > LEVEL_WIDTH ) )
    {
        //Move back
        d->mPosX -= d->DOT_VEL;
    }

    //Move the dot up or down
    d->mPosY += d->DOT_VEL;

    //If the dot went too far up or down
    if( ( d->mPosY < 0 ) || ( d->mPosY + d->DOT_HEIGHT > LEVEL_HEIGHT ) )
    {
        //Move back
        d->mPosY -= d->DOT_VEL;
    }

}
*/
SDL_Surface* loadSurface(char* path)
{
    //Final Optimized Image
    SDL_Surface* optSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path);

    if(loadedSurface == NULL)
    {

        printf("SOMETHING WENT WRONG WHILE LOADING IMAGE:%s", path);
    }
    else{
        //Convert to screen format
        optSurface = SDL_ConvertSurface(loadedSurface, screen->format,(int)NULL);
        if(optSurface == NULL)
        {
            printf("Unable To optimize image");

        }

        //Free the Old image
        SDL_FreeSurface(loadedSurface);
    }
    return optSurface;
}

int loadImage()
{

   // SDL_Surface* gImage;
    int success = 1;

    image = SDL_LoadBMP("sample.bmp");

    if(image == NULL)
    {

        printf("Unable to load image %s! SDL Error:%s\n", "sample.bmp",SDL_GetError());
        success = 0;
    }

    return success;

}

int loadMedia()
{

   // SDL_Surface* gImage;
    int success = 1;

    texture = loadTexture("sample.bmp");

    if(texture == NULL)
    {

        printf("Unable to load image %s as texture! SDL Error:%s\n", "sample.bmp",SDL_GetError());
        success = 0;
    }

    return success;

}

double Interpolate(double goal, double c, double time)
{
    double diff = goal  - c;

    if(diff > time)
    {
        return c + time;
    }
    if(diff < -time)
    {
        return c - time;

    }
    else{return goal;}



}

SDL_Texture* loadTexture( char c [])
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( c );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", c, IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", c, SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}


void SetupWindow()
{
   // IMG_Init();
    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO < 0))
    {
        printf("Could Not Start SDL!\n");
    }
    else
        {
        //Create Window
        win = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(win == NULL)
            {
                printf("Could not create window...\n");
            }
            else
                {

                   renderer = SDL_CreateRenderer(win, -1 , SDL_RENDERER_ACCELERATED);
                   if(renderer == NULL)
                    {

                        printf("Error Creating Renderer Instance!\n");
                    }
                    else
                    {
                            SDL_SetRenderDrawColor(renderer, 0xFF , 0xFF , 0xFF , 0xFF);

                            //Init PNG loading
                            int imgFlags = IMG_INIT_PNG;
                            if(!(IMG_Init(imgFlags)&imgFlags))
                            {

                                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                            }

                     }
                  }

        }
}

void close()
{
    free(gridToUse);
    SDL_DestroyTexture(texture);
    texture = NULL;
    //Deallocate Surfaces
    SDL_FreeSurface(image);
    image = NULL;

    //Destroy Wiondow
    SDL_DestroyWindow(win);
    win = NULL;

    //Quit SDl
    IMG_Quit();
    SDL_Quit();
}

void cameraSetup()
{

                      //Center the camera over the
/*
                camera.x = ( dot.getPosX() + Dot::DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2;
                camera.y = ( dot.getPosY() + Dot::DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

                //Keep the camera in bounds
                if( camera.x < 0 )
                {
                    camera.x = 0;
                }
                if( camera.y < 0 )
                {
                    camera.y = 0;
                }
                if( camera.x > LEVEL_WIDTH - camera.w )
                {
                    camera.x = LEVEL_WIDTH - camera.w;
                }
                if( camera.y > LEVEL_HEIGHT - camera.h )
                {
                    camera.y = LEVEL_HEIGHT - camera.h;
                }

                 //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                //Render background
                gBGTexture.render( 0, 0, &camera );

                //Render objects
                dot.render( camera.x, camera.y );

                //Update screen
                SDL_RenderPresent( gRenderer );
                */
}

void Initialize()
{
    int j =0;
    int i  = 0 ;
    SDL_Event e;
    if(loadMedia()!= 1) printf("Could not load texture");
     //Set the wall
            SDL_Rect wall;
            wall.x = 300;
            wall.y = 40;
            wall.w = 40;
            wall.h = 400;
    //SDL_Color textColor = {0,0,0,255};
    //dot_struct d;
    //SDL_Rect camera = {0,0,SCREEN_HEIGHT,SCREEN_WIDTH};

   // gridToUse = createGrid();
   // if(gridToUse ==  NULL) printf("ERROR CREATING GRID");
    SetupWindow();
    //loadMedia();

    //Main Loop
    while( i == 0)
    {
        while(SDL_PollEvent(&e)!= 0)
        {
            //keyboardInput(e);
            if(e.type == SDL_QUIT)
            {

                i = 1;
            }


        }


        //This here is basically a double buffer
       // moveDot(wall);
        //Clear Screen
         SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(renderer);

        //createMap();
          //SDL_RenderDrawRects(renderer , gridToUse,256) ;

        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        SDL_RenderDrawRect(renderer,&wall);
        renderDot(dot,texture);

        //Render texture to screen
        //SDL_RenderCopy(renderer, texture,NULL,NULL);

        //Update Screen
        SDL_RenderPresent(renderer);
    }



      //window stays open for 2 seconds
    SDL_Delay(2000);

    close();




 //   initPlayer(&player);
   // initCamera(&cam);

}


void createMap()
{
    SDL_Rect bottomRightViewport;
    bottomRightViewport.x = SCREEN_WIDTH/ 2;
    bottomRightViewport.y = SCREEN_HEIGHT / 2;
    bottomRightViewport.w = SCREEN_WIDTH;
    bottomRightViewport.h = SCREEN_HEIGHT;

    SDL_RenderSetViewport(renderer, &bottomRightViewport);

    //Render the texture
    SDL_RenderCopy(renderer, texture, NULL,NULL);

}


void Pause()
{
    //set running to false
}

void cleanUp(char_strct *player, cam_strct *cam)
{
    SDL_DestroyTexture(texture);
    texture = NULL;

    SDL_DestroyWindow(win);
    win = NULL;
    renderer = NULL;

    //Free Graphical Interface
    IMG_Quit();
    SDL_Quit();
    //freeGrid();
    exitPlayer(player);
    freeCamera(cam);

}

void update(SDL_Surface* surf, SDL_Surface* dest,int x, int y)
{
    SDL_Rect destR;
    destR.x = x;
    destR.y = y;

    SDL_BlitSurface(surf,NULL,dest,&destR);
}

void render(int x, int y , SDL_Rect * src,SDL_Texture* texture)
{
    SDL_Rect dest = {x,y,960 , 614};

    /*if(src != NULL)
    {

        dest.w = src->w;
        dest.h = src->h;
    }
*/
    SDL_RenderCopy(renderer, texture,NULL, NULL);
}


int main()
{
    //enum_bool isDebugging =true;

    //if(isDebugging)
    //{
    debugging();
    Initialize();
    //}
    // run();
    return 0;
}

