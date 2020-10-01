#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
    const char* number[10]= {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = a ; i<=9 && i<=b ; i++){
      printf("%s\n" , number[i-1]);
    }
    for(int j = 10 ; j<=b ; j++ ){
        if (j%2==0)
        printf("even\n");
        else 
        printf("odd\n");
        
    }

    return 0;
}

