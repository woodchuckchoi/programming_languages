#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h> // getsockopt와 setsockopt 함수 제공

void error_handling(char *message);

int main(int argc, char **argv) {
	int sock;
	int snd_buffer, rcv_buffer;
	socklen_t len;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	len = sizeof(snd_buffer);
	if (getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (void *)&snd_buffer, &len) < 0)
		error_handling("GETSOCKOPT ERROR");

	len = sizeof(rcv_buffer);
	if (getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buffer, &len) < 0)
		error_handling("GETSOCKOPT ERROR");

	printf("INPUT BUFFER SIZE :%d\n", rcv_buffer);
	printf("OUTPUT BUFFER SIZE :%d\n", snd_buffer);
	return 0;
} 

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
