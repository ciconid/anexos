#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

	if (argc != 2){
		printf("Ingrese solo la cantidad de terminos \n");
		printf("./anx3-17 <cant_term> \n");
		exit(EXIT_FAILURE);
	}

	int terminos = atoi(argv[1]);
	if (terminos < 1) {
		printf("Ingrese cantidad de terminos mayor o igual a 1");
		exit(EXIT_FAILURE);
	}

	// creacion del pipe
	int fd[2]; // fd es "file descriptor"... se pude elegir cualquier nombre
		   // fd[0] --> extremo de lectura
		   // fd[1] --> extremo de escritura
	pipe(fd); // crea el pipe

	pid_t pid = fork();

	if (pid < 0) {
		printf("Error en fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		close(fd[0]);// cierro el extremo de lectura
		
		// calcular fib
		int fib_n_minus_2 = 0;
		int fib_n_minus_1 = 1;
		int fib_n;

		for (int i = 1; i <= terminos; i++) {
			if (i == 1) {
				fib_n = 0;
			} else if (i == 2) {
				fib_n = 1;
			} else {
				fib_n = fib_n_minus_1 + fib_n_minus_2;
					
				fib_n_minus_2 = fib_n_minus_1;
				fib_n_minus_1 = fib_n;
			}
			
			write(fd[1], &fib_n, sizeof(fib_n) );
		}

		close(fd[1]); // cierro extremo escritura antes de terminar
		exit(EXIT_SUCCESS);


	} else { // padre
		close(fd[1]); // cierro extremo de escritura
			
	  	int fib;
		for (int i = 1; i <= terminos; i++) {
			read(fd[0], &fib, sizeof(fib));
			printf("PADRE: %d \n", fib);
		}

		int status;
		wait(&status); // con wait(NULL) padre solo espera que el hijo termine
			       // sin importar su codigo de salida
		close(fd[0]);
	}





	exit(EXIT_SUCCESS);

}
