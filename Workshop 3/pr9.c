#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b){
    while(a!=b)
        if (a>b)
            a-=b;
        else
            b-=a;
    return a;
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main(int argc, char** argv) {
    int a,b,d,m;
    do{
        printf("Enter number 1:");
        scanf("%d",&a);
        printf("Enter number 2:");
        scanf("%d",&b);
    }while(a<=0||b<=0);
    d=gcd(a,b);
    m=lcm(a,b);
    printf("The greatest common divisor is:%d\n",d);
    printf("The least common multiple is:%d",m);
    return 0;
}

