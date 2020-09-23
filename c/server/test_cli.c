#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char **argv) {
	if (argc < 3) 
		error_handling("NOT ENOUGH ARGS");
	int client;
	struct sockaddr_in server_addr;
	char buffer[1024] = {0x00, };

	client = socket(AF_INET, SOCK_STREAM, 0);
	if (client == -1)
		error_handling("SOCKET ERROR");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(*(argv+1));
	server_addr.sin_port = htons(atoi(*(argv+2)));

	if (connect(client, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
		error_handling("CONNECT ERROR");

	if (read(client, buffer, sizeof(buffer)-1) == -1)
		error_handling("READ ERROR");
	printf("MESSAGE FROM SERVER : %s\n", buffer);

	close(client);
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
