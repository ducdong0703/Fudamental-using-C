#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 100
void clear(){
    while(getchar() != '\n');
}

int checkInput(int min, int max){
    int opt, keeptrying = 1, rc;
    char after;
    do{
        rc = scanf("%d%c", &opt, &after);
        if(rc == 0){
            printf("No input accepted!\n");
            clear();
        }
        else if(after != '\n'){
            printf("Trailing characters!\n");
            clear();
        }
        else if(opt < min || opt > max){
            printf("No option!\n");
        }
        else
            keeptrying = 0;
    }while(keeptrying == 1);
    return opt;
}

char* lTrim(char name[]){
    int i = 0;
    while(name[i] == '  ')
        i++;
    if(i>0)
        strcpy(&name[0], &name[i]);
    return name;
}

char* rTrim(char name[]){
    int i = strlen(name) - 1;
    while(name[i] == '  ')
        i--;
    name[i+1] = '\0';
    return name;
}

char* trim(char name[]){
    rTrim(lTrim(name));
    char* ptr = strstr(name, "  ");
    while(ptr != NULL){
        strcpy(ptr, ptr + 1);
        ptr = strstr(name, "  ");
    }
    return name;
}

char* nameStr(char name[]){
    trim(name);
    strlwr(name);
    int L = strlen(name);
    int i;
    for(i=0; i < L; i++)
            name[i] = toupper(name[i]);
    return name;
}

void add(char name[][50], int *count){
    char temp[50];
    int check = -1;
    printf("Enter student name:");
    fflush(stdin);
    scanf("\n%[^\n]", temp);
    nameStr(temp);
    for(int i = 0 ; i < *count; i++)
        if(strcmp(name[i], temp) == 0)
            check = 0;
    if(check == 0)
        printf("This name already in list!\n");
    else{
        strcpy(name[*count], temp);
        nameStr(name[*count]);
        (*count)++;
        printf("Added\n");
    }
}

void remov(char name[][50], int *count){
    int i;
    char remove[50];
    int check = -1;
    printf("Enter student name:");
    scanf("\n%[^\n]", remove);
    nameStr(remove);
        for (i = 0; i < *count; i++){
            if (strcmp(name[i], remove) == 0){
                strcpy(name[i], name [i+1]);
                check = 0;
                (*count)--;
            }
        }
        if (check == 0){
            printf("%s is removed\n", remove);
        } 
        else{
            printf("%s is not in the list! Please enter full name!\n", remove);
        }
}

void search(char name[][50], int count){
    int sear[50];
    int i, j;
    int check = -1;
    printf("Enter student name:");
    scanf("\n%[^\n]", sear);
    nameStr(sear);
    for(i = 0; i < count; i++){
            if(strcmp(name[i], sear) == 0){
                check = 0;
            }
        }
    if(check == 0){
         printf("%s is on the list\n", sear);
    }
    else 
        printf("Not found!\n");
}

void ascen(char name[][50], int count){
    int i,j;
    char t[50];
    for(i = 0; i< count-1; i++)
        for(j = count-1; j > i; j--)          
            if(strcmp(name[j], name[j-1]) < 0){
                strcpy(t, name[j]);
                strcpy(name[j], name[j-1]);
                strcpy(name[j-1], t);
            }
}
void print(char name[][50], int count){
    int i;
    for(i = 0; i < count; i++){
        printf("Student %d:", i+1);
        puts(name[i]);
    }
}

void menu(){
    printf("--------MENU--------\n");
    printf("Option 1: Add a student\n");
    printf("Option 2: Remove a student\n");
    printf("Option 3: Search a student\n");
    printf("Option 4: Print the list in ascending order\n");
    printf("Option 5: Quit\n");
    printf("Choose option:");
}
int main(int argc, char** argv) {
    int count = 0;
    char name[MAXN][50];
    int opt;
    char value;
    do{
        system("clear");
        menu();
        opt = checkInput(1,5);
        switch(opt){
            case 1:
                add(name, &count);
                getchar();
                getchar();
                break;
            case 2:
                if(count <= 0){
                    printf("Nothing to remove\n");
                    getchar();
                }
                else{
                    remov(name, &count);
                    getchar();
                    getchar();
                }
                break;
            case 3:
                if(count <= 0){
                    printf("Nothing to search!\n");
                    getchar();
                }
                else
                {
                    search(name, count);
                    getchar();
                    getchar();
                }
                break;
            case 4:
                ascen(name, count);
                printf("-----List of Student-----\n");
                print(name, count);
                getchar();
                break;
            case 5:
                printf("Have a nice day!\n");
                return 0;
        }
    }while(opt != 5);
    return (EXIT_SUCCESS);
}

