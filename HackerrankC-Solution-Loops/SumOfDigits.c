#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    
    int a = n%10;
    n= n/10;
    int b = n%10;
    n= n/10;
    int c = n%10;
    n= n/10;
    int d = n%10;
    n= n/10;
    int e = n%10;
    n= n/10;
    int f = a+b+c+d+e;
    printf("%d", f);
    return 0;
}
