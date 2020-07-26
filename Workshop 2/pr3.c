#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    int sum,x;
    printf("x: ");
    scanf("%d",&x);
    do{
         sum += x;
         scanf("%d",&x);
    }while(x!=0);
    printf("Sum is:%d",sum);
    return (0);
}

