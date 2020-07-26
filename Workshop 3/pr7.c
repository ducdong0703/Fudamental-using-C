#include <stdio.h>
#include <stdlib.h>
int sumDigits(int n){
    int sum=0;
    do{
        int remainder = n%10;
        n=n/10;
        sum += remainder;
    } while(n>0);
    return sum;
}
int main(int argc, char** argv) {
    int n,s;
    do{
        printf("Enter a number:");
        scanf("%d",&n);
    
    if (n>=0){
        s= sumDigits(n);
        printf("Sum is:%d\n",s);
    }}  while (n>=0);         
    return (0);
}

