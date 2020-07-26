#include <stdio.h>
#include <stdlib.h>
double makeDouble(int ipart, int fraction){
    double d_f=fraction;
    while (d_f>=1)
        d_f=d_f/10;
    if(ipart<0)
        return ipart - d_f;
    return ipart + d_f;
}
int main(int argc, char** argv) {
    int ipart, fraction;
    double value;
    printf("Enter integral part:");
    scanf("%d",&ipart);
    do{
        printf("Enter fraction part:");
        scanf("%d",&fraction);
      } while(fraction <0);
    value=makeDouble(ipart,fraction);
    printf("The number is:%lf",value);
    return 0;
}

