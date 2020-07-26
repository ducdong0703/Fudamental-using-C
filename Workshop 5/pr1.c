#include <stdio.h>
#include <stdlib.h>
void clear(){
    while(getchar()!='\n');
}
void isValid(int value, char after){
    int rc;
    rc=("%d%c",value,after);
    if (rc==0||after!='\n'){
        printf("Invalid value!\n");
        clear();
    }
    else if(value<2||value>12)
        printf("Out of range!\n");
}
void total(int total){
    int count,x,y;
    do{
        count++;
        x=rand()%6+1;
        y=rand()%6+1;
        printf("Result of throw %d:%d+%d\n",count,x,y);
    }while(x+y!=total);
    printf("You got your total in %d throws!",count);    
}
int main(int argc, char** argv) {
    srand(time(NULL));
    int n,a;
    printf("======Dice throws========\n");
    do{
        printf("Enter total sought:");
        scanf("%d%c",&n,&a);
        isValid(n,a);
    }while(n<2||n>12||a!='\n');
    total(n);
    return (EXIT_SUCCESS);
}

