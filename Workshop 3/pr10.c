#include <stdio.h>
#include <stdlib.h>
void MinMaxDigits(int n){
    int digit, min, max;
    digit=n%10;
    n=n/10;
    min=max=digit;
    while(n>0){
        digit=n%10;
        n=n/10;
        if(min>digit)
            min=digit;
        if(max<digit)
            max=digit;
    }
    printf("Min is:%d\n",min);
    printf("Max is:%d",max);
}
int main(int argc, char** argv) {
    int n;
    do{
        printf("Enter a digit:");
        scanf("%d",&n);
        MinMaxDigits(n);
    }while(n<0);
    return 0;
}

