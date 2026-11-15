/*
** main.c
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "opkene.h"
#include "opkene_terminate.h"
#include "opkene_emxutil.h"
#include "opkene_emxAPI.h"
int main()
{
    /* The initialize function is called automatically from the generated entry-point function. 
       So, a call to initialize is not included here. */ 

/*double disp[1][2];
double m,n;
m=7.0;
n=9.0;

disp[0][0] = m;
disp[0][1] = n;*/
//static double disp[2] = {7 , 9 };
    double *inputVec; 
    double *outputVec;
    char *str;
   inputVec=(double*)malloc(2 * sizeof(double));
   outputVec=(double*)malloc(1 * sizeof(double));
   str=(char*)malloc(10 * sizeof(char));
   emxArray_real_T *x;
   emxArray_real_T *y;
   emxArray_char_T *fileName;
   
 //"tipper.fis";
 //{'t','i','p','p','e','r','.','f','i','s'};
        
   //emxArray_char_T *fileName = emxCreateWrapper_real_T(NULL,1,11);
           fileName = emxCreateWrapper_char_T(&str[0],1,10);
   x = emxCreateWrapper_real_T(&inputVec[0],1,2);
           //emxCreateWrapper_real_T(NULL,2,1);
           //x = emxCreateWrapper_real_T(disp,2,1);
   x->data[0] = 7;
    x->data[1] = 9;
    fileName->data = "tipper.fis";
  // double t[1];  
  // emxArray_real_T *y = emxCreateWrapper_real_T(t,1,1);
   y = emxCreateWrapper_real_T(&outputVec[0],1,1);
   
   opkene(fileName,x,y);
   
    printf("opkene=%f\n", y->data );
    printf("opkene=%f\n", y->data[0] );
    printf("opkene=%d\n", y[0] );
    printf("opkene=%u\n", y[0] );
    printf("matris=%f\n", x->data );
    printf("matris=%s\n", fileName->data );
   // printf("matris=%d\n", datax[2] );
   printf("m=%f\n", x->data[0] );
   printf("m=%f\n", x->data[1] );
    //printf("at=%u\n", t[1] );
    
    opkene_terminate();
    
    return 0;
}