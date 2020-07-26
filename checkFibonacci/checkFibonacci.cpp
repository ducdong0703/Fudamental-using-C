#include <stdio.h>
#include <stdlib.h>
int checkFibonacci(int n) {
    //==Begin your codes here=====================
	int t1= 1, t2=1, f= 1;
	while(f<n){
		f= t1+t2;
		t1 = t2;
		t2 = f;
	}
	return f==n;

    //==End your codes============================
}
int main(int argc, char *argv[]) {
	system("cls");
	printf("\nTEST Q1 (2 marks):\n");
	int n;
	do {
		printf("Enter n = ");
		scanf("%d", &n);
	} while (n < 2||n>2E9);
	printf("\nOUTPUT:\n");
	if (checkFibonacci(n) == 1)
		printf("%d is Fibonacci.\n", n);
	else
		printf("%d isn't Fibonacci.\n", n);
	system ("pause");
	return 0;
}
