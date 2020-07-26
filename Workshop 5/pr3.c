#include <stdio.h>
#include <stdlib.h>
void clear(){
    while(getchar()!='\n');
}
int isValid(int value,char after){
    int rc;
    rc=("%d%c",value,after);
        if(rc==0||after!='\n'){
            printf("Invalid input!\n");
            clear();
        }
    return value;
}
void charData(char a,char b){
    if(b<a){
        for(char i=a;b<=i;i--)
        printf("%c:%d,%Xh\n",i,i,i);
    }
    else if(a<b){
        for(char i=b;a<=i;i--)
        printf("%c:%d,%Xh\n",i,i,i);
    }
    
}
int validDate(int d, int m, int y){
    int maxd=31;
    if(d<1||d>31||m<1||m>12)
        return 0;
    if(m==4||m==6||m==9||m==11)
        maxd=30;
    else if(m==2){
        if(y%400==0||y%4==0&&y%100!=0)
            maxd=29;
        else
            maxd=28;
    }
    return d<=maxd;   
}
int main(int argc, char** argv) {
    int selection;
    char after;
    do{
        printf("=======MENU======\n");
        printf("Selection 1: Processing date data\n");
        printf("Selection 2: Character data\n");
        printf("Selection 3: Quit\n");
        do{      
            printf("Choose Selection:");
            scanf("%d%c",&selection,&after);
            isValid(selection,after);
        }while(after!='\n');
        switch(selection){
            case 1:{
                int d,m,y;
                char a,b,c;
                do{
                    printf("Enter day:");
                    scanf("%d%c",&d,&a);
                    isValid(d,a);
                }while(a!='\n');
                do{
                    printf("Enter month:");
                    scanf("%d%c",&m,&b);
                    isValid(m,b);
                }while(b!='\n');
                do{
                    printf("Enter year:");
                    scanf("%d%c",&y,&c);
                    isValid(y,c);
                }while(c!='\n');
                if(validDate(d,m,y))
                    printf("Valid Date\n");
                else
                    printf("Invalid Date\n");
                break;
            }
            case 2:{
                char a,b;
                printf("Enter two characters:");
                scanf(" %c%c",&a,&b);
                charData(a,b);
                break;
             }
            case 3:
                printf("Bye!");
                break;
            default:
                printf("No selection!\n");
                break;
        }
    }while(selection!=3);
    return (EXIT_SUCCESS);
}
