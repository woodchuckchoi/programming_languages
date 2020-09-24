#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
	int pid;

	pid = fork();
	if (pid > 0) {
		printf("Parent\n");
		pause();
	} else if (pid == 0) {
		printf("Child\n");
		pause();
	} else {
		fputs("FORK ERROR", stderr);
		exit(1);
	}
	return 0;
}
