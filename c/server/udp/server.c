#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void error_handling(char *msg);

struct data {
	int a;
	int b;
	int sum;
};

int main(int argc, char **argv) {
	int sockfd;
	int client;
	struct data mydata;
	struct sockaddr_un client_addr, server_addr;
	
	sockfd = socket(AF_UNIX, SOCK_DGRAM, 0); // Domain Socket, UDP
	if (sockfd < 0)
		error_handling("SOCKET ERROR");
	unlink(*(argv+1)); // delete a name, possibly, remove the file
	
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sun_family = AF_UNIX;
	strcpy(server_addr.sun_path, *(argv+1));

	if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
		error_handling("BIND ERROR");
	client = sizeof(client_addr);

	while (1) {
		recvfrom(sockfd, (void *)&mydata, sizeof(mydata), 0, (struct sockaddr *)&client_addr, &client);
		printf("%d + %d = %d", mydata.a, mydata.b, mydata.a + mydata.b);
		sendto(sockfd, (void *)&mydata, sizeof(mydata), 0, (struct sockaddr *)&client_addr, client);
	}
	close(sockfd);
	return 0;
}

void error_handling(char *msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
