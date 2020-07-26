#include <stdio.h>
#include <stdlib.h>
int factorial (int n){
    int p=1, i;
    for (i=2;i<=n;i++)
        p *=i;
    return p;
}
int main(int argc, char** argv) {
    int n;
    printf("Enter N:");
    do {
        scanf("%d",&n);
    } while (n<0);
    printf ("Factorial is:%d",factorial(n));
    return (0);
}

