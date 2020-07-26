#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    int  code;
    for (code=0; code <=255;code++)
    {
    printf("%c:%d,%o,%X\n",code,code,code,code);
    if(code!=0 && code %20==0)
        getchar();}
    return (0);
}

