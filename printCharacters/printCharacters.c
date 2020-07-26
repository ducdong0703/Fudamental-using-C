int main(int argc, char** argv) {
    char c1, c2, t;
    int d;
    printf("Enter fist character: ");
    scanf("%c", &c1);
    getchar();
    printf("Enter second character: ");
    scanf("%c", &c2);
    //== Begin your codes======
    if(c1 > c2){
    	for(t = c2; t <= c1; t++)
    		printf("%c%d   ", t,t);
	}
	else{
    	for(t = c1; t<=c2; t++)
    		printf("%c%d     ", t, t);
    
	}
    //== End your codes========
    
    return 0;
}
