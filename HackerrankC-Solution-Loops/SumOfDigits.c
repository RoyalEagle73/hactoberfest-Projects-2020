#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,ind,sum=0;
    scanf("%d", &n);
    while(n>0){
        ind=n%10;
        n=n/10;
        sum+=ind;
    }
    printf("%d",sum);
    return 0;
}
