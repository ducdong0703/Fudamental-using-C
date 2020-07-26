#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    int x,y;
    printf("x: ");
    scanf("%d",&x);
    printf("y: ");
    scanf("%d",&y);
    do{
        int t=x;
        x=y;
        y=t;
        printf("x is:%d\n",x);
        printf("y is:%d\n",y);
        printf("x: ");
        scanf("%d",&x);
        printf("y: ");
        scanf("%d",&y);
    }while(x!=0 && y!=0);
    return (0);
}

