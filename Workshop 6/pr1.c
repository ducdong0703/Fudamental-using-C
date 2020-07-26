#include <stdio.h>
#include <stdlib.h>
void clear(){
    while(getchar() != '\n');
}

int checkInput(int min,int max){
    int n;
    int rc,keeptrying = 1;
    char after;
    do{
        rc = scanf("%d%c",&n,&after);
        if(rc == 0){
            printf("No input accepted!\n");
            clear();
        }
        else if(after != '\n'){
            printf("Trailing characters!\n");
            clear();
        }
        else if(n < min || n > max)
            printf("Out of range!\n");
        else
            keeptrying = 0;
    }while(keeptrying == 1);
    return n;
}

int isbnValid(int n){
    int I[11];
    int C[10];
    int i,j,result = 0;
    for(i = 10;i > 0;i--){
        I[i] = n%10;
        n = n/10;
    }
    for(j = 1;j < 10;j++){
        C[j] = I[j]*(11-j);
        result += C[j];
    }
    result = result+I[10];
    if(result%11 == 0)
        return 1;
    else
        return 0;
}

int main(int argc, char** argv) {
    int isbn;
    do{
        printf("======ISBN validator======\n");
        printf("ISBN (0 to quit):");
        isbn = checkInput(0,1000000000);
        if(isbn == 0){
            printf("Have a Nice Day!\n");
        }
        else{
            if(isbnValid(isbn) == 1)
                printf("This is a valid ISBN\n");
            else
                printf("This is not a valid ISBN\n");
        }
    }while(isbn != 0);
    return (EXIT_SUCCESS);
}

