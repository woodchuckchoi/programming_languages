#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void error_handling(char *msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main() {
	int fd;
	char buf[255];
	int state;

	struct timeval tv;
	fd_set readfds, writefds;
	fd = fileno(stdin);

	while (1) {
		FD_ZERO(&readfds);
		FD_SET(fd, &readfds);

		tv.tv_sec = 10;
		tv.tv_usec = 0;

		state = select(fd + 1, &readfds, (fd_set *)0, (fd_set *)0, &tv);
		switch (state) {
			case -1:
				error_handling("SELECT ERROR");
				break;
			case 0:
				printf("TIME OVER\n");
				close(fd);
				exit(0);
				break;
			default:
				fgets(buf, 255, stdin);
				printf("%s\n", buf);
				break;
		}
	}
}
