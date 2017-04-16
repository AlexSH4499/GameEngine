#include"matrices.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void loadIdentity44(float matrix[][4])
{
    //x = *((int *)y + a * NUM_COLS + b)
    //element = *(*( first_element + row -1) + column-1);
    // 1 0 0 0
    // 0 1 0 0
    // 0 0 1 0
    // 0 0 0 1
    // *((matrix + 0)+0) = *((matrix+1)+1) = *((matrix+2)+2) = *((matrix+3)+3)= 1.0f;
    *matrix[0] = 1.0f;
    *matrix[5] = 1.0f;
    *matrix[10]= 1.0f;
    *matrix[15]= 1.0f;
    //  memset(matrix,0x00,sizeof(matrix));

}

void transposeMatrix44(float *m1, float *m2) //4x4
{
    int i, j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            m2[j+i*4]=m1[i+j*4];
        }
    }
}

//GOTTA ADAPT THESE TO 2 DIMENSIONAL ARRAYS!!!!!!!
mvector multMatrix44Vect(float *m, mvector v, enum_bool transpose)
{
    /*if(!transpose){
                    return
                            mvector(dotProd(v, mvector(m[0+0*4], m[1+0*4], m[2+0*4])),
                            dotProd(v, mvector(m[0+1*4], m[1+1*4], m[2+1*4])),
                            mvector(v, mvector(m[0+2*4], m[1+2*4], m[2+2*4])));
                  }
    else{
                    return
                            mvector(dotProd(v, mvector(m[0+0*4], m[0+1*4], m[0+2*4])),
                            dotProd(v, mvector(m[1+0*4], m[1+1*4], m[1+2*4])),
                            dotProd(v, mvector(m[2+0*4], m[2+1*4], m[2+2*4])));
        }
        */
}

//GOTTA ADAPT THESE TO 2 DIMENSIONAL ARRAYS!!!!!!!
/*mvector4D multMatrix44Vect4(flo*(*(matrix+2)+2)at *m, mvector4D v, enum_bool transponse)
{
       if(!transpose) return mvector4D(dotProd4D(v, mvector4D(m[0+0*4], m[1+0*4], m[2+0*4], m[3+0*4])), dotProd4D(v, mvector4D(m[0+1*4], m[1+1*4], m[2+1*4], m[3+1*4])), dotProd4D(v, mvector4D(m[0+2*4], m[1+2*4], m[2+2*4], m[3+2*4])), dotProd4D(v, mvector4D(m[0+3*4], m[1+3*4], m[2+3*4], m[3+3*4])));
	else           return mvector4D(dotProd4D(v, mvector4D(m[0+0*4], m[0+1*4], m[0+2*4], m[0+3*4])), dotProd4D(v, mvector4D(m[1+0*4], m[1+1*4], m[1+2*4], m[1+3*4])), dotProd4D(v, mvector4D(m[2+0*4], m[2+1*4], m[2+2*4], m[2+3*4])), dotProd4D(v, mvector4D(m[3+0*4], m[3+1*4], m[3+2*4], m[3+3*4])));

}
*/
void addMatrix44(float m1[][4],float m2[][4],float m[][4])
{
    int i,j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            *(*(m+i)+j) = (float) *(*(m1+i)+ j)+(float) *(*(m2+i)+j);
        }
    }
}
void subtractMatrix44(float *m1, float *m2,float *m)
{
    int i,j;
/*
    for(i = 0; i< 4; i++)
    {
        for(j= 0; j<4; j ++)
        {
            *(*(m+i)+j) = (float) *(*(m1+i)+j)-(float) *(*(m2+i)+j);
        }
    }
    */
}

void multiplyMatrix44(float *m1, float  *m2, float *m)
{
    //There's a bug here that fails to assign values to the proper indexes
    int i,j;

    for(i=0; i<4 ; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("i = %d ,j = %d\n\n",i,j);
            printf("value stored in m1[%d][%d] = %f\n",i,j,*((m1 + i)+j));
            printf("value stored in m2[%d][%d] = %f\n",i,j,*((m2 + i)+j));
            *((m+i)+j) =
                (float)  (*((m1+0)+j) **((m2+i)+0))+ (*((m1+1)+j) **((m2+i)+1)) +
                (float) (*((m1+2)+j) * *((m2+i)+2)) + (*((m1+3)+j) **((m2+i)+3));
            printf("Value stored in m[%d][%d] = %f\n\n", i,j,*((m+i)+j));
        }
    }
}
/*
   0 0 0 x
   0 0 0 y
   0 0 0 z
   0 0 0 0
*/

void translateMatrix44(float *temp,float x, float y, float z)
{

    // float matri[4][4];
    float rm[4][4];

    loadIdentity44(rm);
    rm[0][3] = x;
    rm[1][3] = y;
    rm[2][3] = z;

    //multMatrix44(temp,rm, matri);
    //memcpy(temp, matri,16*sizeof(float));

}
/*
    x * s   y*s     z*s  0*s
    xs1     ys1     zs1  0
    xs2     ys2     zs2  0
    xs3     ys3     zs3  0
    xs4     ys4     zs4  0
*/
void scaleMatrix(float *temp,  float x,float y,float z)
{
    /*
    temp [0][0] *=x;    temp [0][1] *=y;    temp [0][2] *=z;
    temp [1][0] *=x;    temp [1][1] *=y;    temp [1][2] *=z;
    temp [2][0] *=x;    temp [2][1] *=y;    temp [2][2] *=z;
    temp [3][0] *=x;    temp [3][1] *=y;    temp [3][2] *=z;*/
}
/* this is our projection cube for out Field of Vision and perspective change
    @param matrix Matrix pointer that we'll modify
    @param fovy Field of Vision in Y
    @param aspect The ratio of our screen
    @param near The closest point on our box
    @param far The Furthest point on our box

*/
void initProjectMatrix(float *matrix, float fovy, float aspect,float near, float far)
{

    float top = near * tan(fovy/2);
    float right = (top*aspect);

    float matrixP[4][4];

    matrixP[0][0] = near /right;
    matrixP[0][1] = 0.0f;
    matrixP[0][2] = 0.0f;
    matrixP[0][3] = 0.0f;

    matrixP[1][0] = 0.0f;
    matrixP[1][1] = near/top;
    matrixP[1][2] = 0.0f;
    matrixP[1][3] = 0.0f;

    matrixP[2][0] = 0.0f;
    matrixP[2][1] = 0.0f;
    matrixP[2][2] = -(far+near)/(far-near);
    matrixP[2][3] = -2.0f * (far*near)/(far-near);

    matrixP[3][0] = 0.0f;
    matrixP[3][1] = 0.0f;
    matrixP[3][2] =-1.0f;
    matrixP[3][3] = 0.0f;

    float mp2[4][4];
    loadIdentity44(&mp2);
    mp2[2][2]=0.5;
    mp2[2][3]=-0.5;

    // multMatrix44(mp2,matrixP,matrix);

    // rotateMatrixByZAxis(matrix,M_PI/2,false);//false being isTransponse

}

mvector getMatrixColumn33(float matr[][4], int i)
{
    /*if(!matr|| i >= 4)
    {
        printf("not ok");
         return mvector(0,0,0);
    }
    */  mvector vect = {matr[0][i],matr[1][i],matr[2][i]};
    printf("Ok");
    return vect;

}

mvector4D getMatrixColumn44(float m[][4], int i)
{
    /*  if(!m || i >= 5){printf("not ok");return mvector4D(0,0,0,0);}

      printf("ok");
      return mvector4D(m[0][i],m[1][i], m[2][i],m[3][i]);
    */
}

mvector getMatrixRow33(float m[][3], int i)
{
    /*
    if(!m|| i >= 4){printf("not ok");return mvector(0,0,0);}

    printf("ok");
    return mvector(matr[i][0],matr[i][1],matr[i][2]);
    */
}

mvector4D getMatrixRow44(float m[][4],int i)
{
    /*  if(!m || i >= 5){printf("not ok");return mvector4D(0,0,0,0);}

      printf("ok");
      return mvector4D(m[i][0],m[i][1], m[i][2],m[i][3]);
    */
}

void printMatrix(float m[][4], int size)
{
    int i,j;
    for(i=0; i < size ; i++)
    {
        for(j=0; j < size; j++)
        {

            printf("%f|", *(*(m+i)+j));

        }
        puts("\n");
    }

    puts("\n");
}

void testMatrices()
{

    puts("Matrices Tests:\n\n");

    float m[4][4] =
    {
        {1.0,1.0,1.0,1.0},
        {1.0,1.0,1.0,1.0},
        {1.0,1.0,1.0,1.0},
        {1.0,1.0,1.0,1.0}
    };

    float m1[4][4] =
    {
        {2.0,2.0,2.0,2.0},
        {2.0,2.0,2.0,2.0},
        {2.0,2.0,2.0,2.0},
        {2.0,2.0,2.0,2.0}
    };

    float m2[4][4] =
    {
        {0.0,0.0,0.0,0.0},
        {0.0,0.0,0.0,0.0},
        {0.0,0.0,0.0,0.0},
        {0.0,0.0,0.0,0.0}
    };

    float m3[4][4]=
    {
        {0.0,0.0,0.0,0.0},
        {0.0,0.0,0.0,0.0},
        {0.0,0.0,0.0,0.0},
        {0.0,0.0,0.0,0.0}
    };

    loadIdentity44(m2);

    puts("Original m:\n");
    printMatrix(m, 4);

    puts("Original m1:\n");
    printMatrix(m1, 4);


    puts("Original m2:\n");
    printMatrix(m2, 4);

    puts("Multiplication of m & m1:\n");
    multiplyMatrix44(m,m1,m3);//something wrong here
    printMatrix(m3, 4);

    puts("Addition of m2 & m1:\n");
    addMatrix44(m2,m1,m2);//and here as well
    printMatrix(m2, 4);

}
