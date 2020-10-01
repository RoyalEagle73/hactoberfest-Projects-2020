#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//we solve it using recurrsion

void patt (int i , int j , int f , int l , int n){
     if(n>=0){
         if(i==f || i==l || j==f || j==l){
             printf("%d\t", n);
         }
         else {
           patt( i , j , f+1 , l-1 , n-1);
         }
     }
}
int main() 
{

    int n;
    scanf("%d", &n);
  	for(int i=0; i< 2*n-1; i++){
          for(int j=0; j< 2*n-1; j++){
              patt(i, j, 0, 2*n-2, n);
          }
          printf("\n");
      }
    return 0;
}
