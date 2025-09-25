#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("Ingrese el nivel de arbol a crear (mayor que 0) \n");
		exit(EXIT_FAILURE);
	}

	int n = atoi(argv[1]);
	if (n < 1) {		
		printf("Ingrese el nivel de arbol a crear (mayor que 0) \n");
		exit(EXIT_FAILURE);
	}

	
	printf("Nivel=0 PID=%d PPID=%d \n", getpid(), getppid());
	for (int i = 1; i < n; i++) {
		fork();

		printf("Nivel=%d PID=%d PPID=%d \n", i, getpid(), getppid());
	}


	for (int i = 1; i < n; i++) {
		int status;
		wait(&status);
	}

	exit(EXIT_SUCCESS);


}
