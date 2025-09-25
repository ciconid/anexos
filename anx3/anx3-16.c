#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

	if (argc != 2){
		printf("Ingrese solo la cantidad de terminos \n");
		printf("./anx3-16 <cant_term> \n");
		exit(EXIT_FAILURE);
	}

	int terminos = atoi(argv[1]);
	if (terminos < 1) {
		printf("Ingrese cantidad de terminos mayor o igual a 1");
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork();

	if (pid < 0) {
		printf("Error en fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		// calcular e imprimir fib
		int fib_n_minus_2 = 0;
		int fib_n_minus_1 = 1;
		int fib_n;

		for (int i = 1; i <= terminos; i++) {
			if (i == 1) {
				printf("0 \n");
			} else if (i == 2) {
				printf("1 \n");
			} else {

				fib_n = fib_n_minus_1 + fib_n_minus_2;
				printf("%d \n", fib_n);
				
				fib_n_minus_2 = fib_n_minus_1;
				fib_n_minus_1 = fib_n;
			}
		}

		exit(EXIT_SUCCESS);


	} else {
		int status;
		wait(&status); // con wait(NULL) padre solo espera que el hijo termine
			       // sin importar su codigo de salida
	}





	exit(EXIT_SUCCESS);

}
