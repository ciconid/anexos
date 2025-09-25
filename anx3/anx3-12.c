#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	
	//  chequeo de uso correcto de parametros
	if (argc != 2) {
		printf("Ingrese numero de hijos a crear como parametro \n");
		printf("Ej: ./anx3-12 3 \n");
		exit(EXIT_FAILURE);
	}

 
	int hijos = atoi(argv[1]);
	if (hijos <= 0) {
		exit(EXIT_SUCCESS);
	}

	pid_t pid;
	
	for (int i = 0; i < hijos; i++) {

		//printf("i=%d \n", i);
		pid = fork();


		if (pid == -1) {
			perror("Error al hacer fork() \n");
			exit(EXIT_FAILURE);
		} else if (pid == 0) { // hijo
			//printf("sleep(%d) \n",i);
			printf("PID=%d PPID=%d \n", getpid(), getppid());
			sleep(i);
			printf("Saliendo de hijo %d \n",i);
			exit(EXIT_SUCCESS);
		} else {
			// Esto genera una ejecucion secuencial
			//int status;
			//wait(&status);
			//sleep(2);
			//printf("Soy el padre y mi hijo termino con %d \n", WEXITSTATUS(status));
		}
	}

	// Aca el padre espera a cada uno de los hijos
	for (int i = 0; i < hijos; i++) {
		int status;
		wait(&status);
		printf("Soy el padre y mi hijo termino con %d \n", WEXITSTATUS(status));
	}

	printf("Saliendo de padre \n");	
	exit(EXIT_SUCCESS);
}
