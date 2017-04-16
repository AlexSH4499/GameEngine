#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "vectors.h"

typedef enum bool
{
    false, true

} enum_bool;

typedef float matrix[4][4];

void loadIdentity44(float matrix[][4]);//If error change back to void and add float* m  arg
void tranlsateMatrix44(float *matrix,mvector4D *mvect);
void addMatrix44(float m1[][4], float m2[][4],float m[][4]);
void multMatrix44(float *m1,float *m2, float *m);
void testMatrices();

void printMatrix(float m[][4], int siz);


mvector4D getMatrixRow44(float m[][4], int i);
mvector4D getMatrixColumn44(float m[][4],int i);



#endif // MATRICES_H_INCLUDED
