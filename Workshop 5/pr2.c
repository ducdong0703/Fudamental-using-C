#include <stdio.h>
#include <stdlib.h>
void clear(){
    while(getchar()!='\n');
}
void isValid(int value,char after){
    int rc;
    rc=("%d%c",value,after);
        if(rc==0||after!='\n'){
            printf("Invalid input!\n");
            clear();
        }
        else if(value<2||value>20){
            printf("Out of range!\n");
        }
}
void total(int total){
    int count=1,x,y;
    do{
        x=rand()%10+1;
        y=rand()%10+1;
        printf("Result picks %d and %d: %d+%d\n",count,count+1,x,y);
        count+=2;
    }while(x+y!=total);
    printf("You got your total in %d picks!",count-1);
}
int main(int argc, char** argv) {
    srand(time(NULL));
    int n;
    char a;
    printf("======Ball Lottery======\n");
    do{
        printf("Enter total sought:");
        scanf("%d%c",&n,&a);
        isValid(n,a);
    }while(n<2||n>20||a!='\n');
    total(n);
    return (EXIT_SUCCESS);
}

