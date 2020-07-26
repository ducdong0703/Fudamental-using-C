#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime(int n){
    int m = sqrt(n);
    int i;
    for (i=2;i<=m;i++)
        if (n%i==0)
            return 0;
    return 1;
}
int main(){
    int n,i;
    printf("N:");
    do{
    scanf("%d",&n);
    }
    while (n<2);
    for (i=2;i<=n;i++){
        if(prime(i))
            printf("%d\t",i);
    }
    return 0;
}

