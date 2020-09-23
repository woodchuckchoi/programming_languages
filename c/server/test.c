#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // sockaddr_in, read, write, etc
#include <arpa/inet.h> //htnol, htons, INADDR_ANY, sockaddr_in, etc
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char **argv) {
	int server;
	int client;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;

	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server == -1)
		error_handling("SOCKET ERROR");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port=htons(atoi(*(argv+1)));

	printf("%d Socket has been opened\n", server);
	
	if (bind(server, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
		error_handling("BIND ERROR");

	if (listen(server, 5) == -1) // Server Queue Pool
		error_handling("LISTEN ERROR");

	client_addr_size = sizeof(client_addr);
	while (1) {
		client = accept(server, (struct sockaddr *)&client_addr, &client_addr_size);
		if (client == -1)
			error_handling("ACCEPT ERROR");
		
		printf("%d client is connected\n", client);

		char msg[] = "Hyuck is currently testing\n";
		write(client, msg, sizeof(msg));
	
		close(client);
	}
	close(server);

	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
