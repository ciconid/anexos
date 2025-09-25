#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	
	pid_t pid;
	pid_t padre = getpid();
	printf("Padre PID=%d \n", padre);

	bool printed = false;

	for (int i = 0; i < 4; i++) {
		
		if (getpid() == padre) {
			pid = fork();
			//printf("pid=%d \n",pid);
		}

		if (pid < 0) {
			perror("Error en fork \n");
			exit(EXIT_FAILURE);
		}

		if (!printed && pid == 0) {
			printf("PID=%d PPID=%d \n", getpid(), getppid());
			printed = true;
			sleep(2);
			printf("PID=%d PPID=%d \n", getpid(), getppid());
		}
	}


	exit(EXIT_SUCCESS);
}
