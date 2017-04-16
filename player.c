
#include "player.h"
#include "vectors.h"


void initPlayer(char_strct* character)
{
    //Need to add the sprites and such
    mvector v = {0.0,0.0,0.0};
    character->speed = 0.0;
    //Read position from a file
    character->position = v;
    character->maxi = v;
    character->hurtBox.position = v;
    character->hurtBox.maxi = v;
    character->isMoving = false;

}

void movePlayer(char_strct* character,mvector *velocity)
{
    //Also needs sprite
    character->isMoving = true;

    character->position = addVectors(&character->position, velocity);
    character->maxi = addVectors(&character->maxi, velocity);

    character->hurtBox.position = addVectors(&character->hurtBox.position,velocity);
    character->hurtBox.maxi = addVectors(&character->hurtBox.maxi,velocity);

    //we need to receive the value from the controls
    //if(keys.RIGHT)
    //character.position = addVectors(character->position,(1.0,0.0,0.0));

}

void exitPlayer(char_strct* character)
{
    // free(&character);
}

void testPlayer(char_strct* character)
{
    mvector v = {0.0,0.0,0.0};
    mvector u = {1.0,1.0,1.0};

    character->maxi = u;
    character->position = v;

    character->isMoving  = true;

    character->hurtBox.maxi = u;
    character->hurtBox.position = v;

    puts("Character Test\n");

    printf("Character is at: (%f, %f, %f)\n\n", character->position.x,character->position.y,character->position.z);
//    printf("Character Hurtbox is at: (%f, %f, %f)", character.hurtBox.position.x,character.hurtBox.position.y,character.hurtBox.position.z);

}

