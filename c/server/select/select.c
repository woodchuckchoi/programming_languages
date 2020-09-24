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
	int fd[2];
	int i, n, state;
	char buf[255];

	struct timeval tv;

	fd_set readfds, writefds;

	if ((fd[0] = open("/tmp/testfile", O_RDONLY)) == -1)
		error_handling("FILE OPEN ERROR");
	if ((fd[1] = open("/tmp/testfile2", O_RDONLY)) == -1)
		error_handling("FILE OPEN ERROR");

	memset(buf, 0, 255);

	while (1) {
		FD_ZERO(&readfds);
		FD_SET(fd[0], &readfds);
		FD_SET(fd[1], &readfds);

		state = select(fd[1]+1, &readfds, (fd_set *)0, (fd_set *)0, NULL);
		switch (state) {
			case -1:
				error_handling("SELECT ERROR");
				break;
			default:
				for (i = 0; i < 2; i++) {
					if (FD_ISSET(fd[i], &readfds)) {
						while ((n = read(fd[i], buf, 255)) > 0)
							printf("(%d) [%d] %s", state, i, buf);
					}
				}
					memset(buf, 0, 255);
					break;
		}
		usleep(1000);
	}
}
