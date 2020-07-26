#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    char c1,c2,t,c;
    int d;
    printf("enter c1:"); 
    scanf("%c",&c1);
    printf("enter c2:");
    scanf(" %c",&c2);
    if (c1>c2)
    {t =c1;c1 =c2;c2=t;
    }
    d=c2-c1;
    printf("d:%d\n",d);
    for (c=c1;c<=c2;c++);
    printf("%c:%d,%o,%X\n",c,c,c,c);
    return (0);
}

