#include <stdio.h>
#include <stdlib.h>
int validDate(int d, int m, int y){
    int maxd=31;
    if(d<1||d>31||m<1||m>12)
        return 0;
    if(m==4||m==6||m==9||m==11)
        maxd=30;
    else
        if(m==2){
            if(y%400==0||y%4==0&&y%100!=0)
                maxd=29;
            else
                maxd=28;        
        }
    return d<=maxd;
}
int main(int argc, char** argv) {
    int d,m,y;
    printf("Enter a day:");
    scanf("%d",&d);
    printf("Enter a month:");
    scanf("%d",&m);
    printf("Enter a year:");
    scanf("%d",&y);
    if (validDate(d,m,y))
        printf("Valid Date");
    else
        printf("Invalid date");
    return 0;
}

