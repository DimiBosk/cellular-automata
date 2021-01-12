//
//  main.c
//  CA_3
//
//  Created by Boskos Dimitris on 27/10/20.
//  CA, TwoDime array, OR rule, Periodic, Von Neumann

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cells[5][5]={
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,1,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
};

int rules(int a, int b, int c, int d, int e);
int main() {
    int i,j;
    
          /*time_t t;
          
          // Intializes random number generator
          srand((unsigned) time(&t));

          // Registration of 25 random numbers from 0 and 1
          for( i = 0 ; i < 5 ; i++ ) {
              for(j=0; j<5; j++){
             cells[i][j]=rand() % 2;
              }
          }*/
        printf("The numbers of \'cells\' array are:\n");
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
            printf("%d\t", cells[i][j]);
            }
            printf("\n");
        }
        printf("\n\n--------------------------------\n\n");
    int w,n,e,s,central;
    int newc[5][5];
    for(int k=0; k<5; k++){
        for(int l=0; l<5; l++){
            if(k==0){
                if(l==0){
                    w=cells[k][4];
                    n=cells[4][l];
                    e=cells[k][l+1];
                    s=cells[k+1][l];
                    central=cells[k][l];
                    newc[k][l]=rules(w,n,e,s,central);
                }
                else if(l==4){
                    w=cells[k][l-1];
                    n=cells[4][l];
                    e=cells[k][0];
                    s=cells[k+1][l];
                    central=cells[k][l];
                    newc[k][l]=rules(w,n,e,s,central);
                }
                else{
                    w=cells[k][l-1];
                    n=cells[4][l];
                    e=cells[k][l+1];
                    s=cells[k+1][l];
                    central=cells[k][l];
                    newc[k][l]=rules(w,n,e,s,central);
                }
            }
            else if(k==4){
                if(l==0){
                    w=cells[k][4];
                    n=cells[k-1][l];
                    e=cells[k][l+1];
                    s=cells[0][l];
                    central=cells[k][l];
                    newc[k][l]=rules(w,n,e,s,central);
                }
                else if(l==4){
                    w=cells[k][l-1];
                    n=cells[k-1][l];
                    e=cells[k][0];
                    s=cells[0][l];
                    central=cells[k][l];
                    newc[k][l]=rules(w,n,e,s,central);
                }
                else{
                    w=cells[k][l-1];
                    n=cells[k-1][l];
                    e=cells[k][l+1];
                    s=cells[0][l];
                    central=cells[k][l];
                    newc[k][l]=rules(w,n,e,s,central);
                }
                
            }
            else{
                w=cells[k][l-1];
                n=cells[k-1][l];
                e=cells[k][l+1];
                s=cells[k+1][l];
                central=cells[k][l];
                newc[k][l]=rules(w,n,e,s,central);
            }
        }
    }
    
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            cells[i][j]=newc[i][j];
        }
    }
    printf("The array after generate is\n");
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%d\t", cells[i][j]);
        }
        printf("\n");
    }
    printf("\n\n--------------------------------\n\n");
    return 0;
}


//OR Rule, if a cell has at elast one non-zero cell in its neighborhood at time t, then
//this cell will take the value 1 at t+1 time
int rules(int a, int b, int c, int d, int e){
    int new;
    if(e==0){
    if(a||b||c||d) new=1;
    else new=e;
    }
    else{
        new=e;
    }
    return new;
}

