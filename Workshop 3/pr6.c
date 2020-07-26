#include <stdio.h>
#include <stdlib.h>
int isFibo(int n){
    int t1=1,t2=1,f=1;
    if(n==1)
        return 1;
    while(f<n){
        f=t1+t2;
        t1=t2;
        t2=f;}
    return n==f;
}
int main(int argc, char** argv) {
    int n;
    printf("Enter a number:");
    do{
        scanf("%d",&n);
    } while (n<1);
    if (isFibo(n)==1)
        printf("It is a Fibonacci element");
    else
        printf("It is not a Fibonacci element");
        
    return (0);
}

