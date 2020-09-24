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
	struct sockaddr_un server_addr;
	int client;
	struct data mydata;

	sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if (sockfd < 0) 
		error_handling("SOCKET ERROR");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sun_family = AF_UNIX;
	strcpy(server_addr.sun_path, *(argv+1));
	client = sizeof(server_addr);

	mydata.a = atoi(*(argv+2));
	mydata.b = atoi(*(argv+3));
	mydata.sum = 0;

	if (sendto(sockfd, (void *)&mydata, sizeof(mydata), 0, (struct sockaddr *)&server_addr, (socklen_t)client) < 0)
		error_handling("SEND ERROR");

	if (recvfrom(sockfd, (void *)&mydata, sizeof(mydata), 0, (struct sockaddr *)&server_addr, (socklen_t *)&client) < 0)
		error_handling("RECV ERROR");

	printf("Result is %d\n", mydata.sum);

	close(sockfd);
	return 0;
}

void error_handling(char *msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

