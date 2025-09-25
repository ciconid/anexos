#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main() {
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		value += 15;
		return 0;
	} else if (pid > 0) {
		wait(NULL);
		printf("PADRE: valor = %d", value);
		return EXIT_SUCCESS;
	}
}

