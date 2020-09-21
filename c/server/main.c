#include <stdio.h>
#include <sys/socket.h> // provides constant variables as well as accept, bind, connect, listen, etc socket-related functions
#include <unistd.h> // for read, write, close functions w/ POSIX interface
#include <stdlib.h> 
#include <netinet/in.h> // provides constant variables for address families (AF_INET for IPV4, AF_INET6 for IPV6, etc)
#include <string.h>

#define PORT 8080

int main() {
	int server_fd, new_socket;
	long valread;

	struct sockaddr_in address;
	int addrlen = sizeof(address);

	char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("IN SOCKET");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	memset(address.sin_zero, '\0', sizeof(address.sin_zero));

	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("IN BIND");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 10) < 0) {
		perror("IN LISTEN");
		exit(EXIT_FAILURE);
	}
	while (1) {
		printf("\n+++++++ Waiting for new connection ++++++++\n\n");
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
			perror("IN ACCEPT");
			exit(EXIT_FAILURE);
		}

		char buffer[1024] = {0};
		valread = read(new_socket, buffer, 1024);
		printf("%s\n", buffer);
		write(new_socket, hello, strlen(hello));
		printf("------------------Hello message sent-------------------\n");
		close(new_socket);
	}
	return 0;
}
