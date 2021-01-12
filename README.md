# cellular-automata
Some simple tasks for cellular automata

//
//  main.c
//  CA_1
//
//  Created by Boskos Dimitris
//  One Dime, rule 90 (mod2), Periodic

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cells[20];
//int ruleset[8]={0,1,0,1,1,0,1,0};
int rules(int a, int b, int c);
int main() {
   int i;
      time_t t;
      
      // Intializes random number generator
      srand((unsigned) time(&t));

      // Registration of 10 random numbers from 0 and 1
      for( i = 0 ; i < 20 ; i++ ) {
         cells[i]=rand() % 2;
      }
    printf("The numbers of \'cells\' array are:\n");
    for(i=0; i<20; i++){
        printf("%d\t", cells[i]);
    }
    printf("\n\n--------------------------------\n\n");
    int newcells[20];
    
    for(int j=0; j<20; j++){
        if(j==0){
            int left=cells[19];
            int middle=cells[j];
            int right=cells[j+1];
            newcells[j]=rules(left, middle, right);
            
        }
        if(j==19){
            int left=cells[j-1];
            int middle=cells[j];
            int right=cells[0];
            newcells[j]=rules(left, middle, right);
            
        }
        else{
            int left=cells[j-1];
            int middle=cells[j];
            int right=cells[j+1];
            newcells[j]=rules(left, middle, right);
            
            
        }
        
    }
    for(i=0; i<20; i++) cells[i]=newcells[i];
    printf("The array after generate:\n");
    for(int k=0; k<20; k++){
        printf("%d\t", newcells[k]);
    }
    
    printf("\n\n--------------------------------\n\n");
    
    return 0;
      }


int rules(int a, int b, int c){
    int new;
    /*if      (a == 1 && b == 1 && c == 1) new= ruleset[0];
    else if (a == 1 && b == 1 && c == 0) new= ruleset[1];
    else if (a == 1 && b == 0 && c == 1) new= ruleset[2];
    else if (a == 1 && b == 0 && c == 0) new= ruleset[3];
    else if (a == 0 && b == 1 && c == 1) new= ruleset[4];
    else if (a == 0 && b == 1 && c == 0) new= ruleset[5];
    else if (a == 0 && b == 0 && c == 1) new= ruleset[6];
    else if (a == 0 && b == 0 && c == 0) new= ruleset[7];*/
    new=(a^c);
    return new;
    
}
