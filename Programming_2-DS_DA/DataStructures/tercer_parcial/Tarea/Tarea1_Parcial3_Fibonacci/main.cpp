#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int x1 = 0;
int x2 = 1;

void fibonacci(int v) {
	if (v != 0) {
		int x3 = x1 + x2;
		x1 = x2;
		x2 = x3;
		printf(" > %d ", x3);
		fibonacci(v - 1);
	}
}

int main(int argc, char** argv) {
	int v;
	printf(" [console] Ingrese la cantidad de numeros de la secuencia fibo quiere: ");
	fflush(stdin);
	scanf("%d", &v);
	printf(" > %d > %d ", x1, x2);
	fibonacci(v-2);
	printf("\n");
	return 0;
}
