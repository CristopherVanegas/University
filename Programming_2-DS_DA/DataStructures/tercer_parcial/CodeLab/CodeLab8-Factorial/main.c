#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	} else {
		return n * factorial(n-1);
	}
}

int main(int argc, char *argv[]) {
	int val;
	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%d", &val);
	printf("Factorial de %d es %d", val, factorial(val));
	return 0;
}
