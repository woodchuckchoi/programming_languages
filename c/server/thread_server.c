#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h> // gcc -pthread flag needed
#include <time.h>

#define BUF_SIZE 100
#define MAX_CLNT 100
#define MAX_IP 30

void *handle_clnt(void *arg);
void send_msg(char *msg, int len);
void error_handling(char *msg);
char *server_state(int count);
void menu(char *port);

int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;

int main(int argc, char **argv) {
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_addr, clnt_addr;
	int clnt_addr_size;
	pthread_t t_id;

	struct tm *t;
	time_t timer = time(NULL);
	t = localtime(&timer);

	if (argc != 2)
		error_handling("ARGUMENT ERROR");

	menu(*(argv+1));

	pthread_mutex_init(&mutx, NULL);
	serv_sock = socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family 		= AF_INET;
	serv_addr.sin_addr.s_addr	= htonl(INADDR_ANY);
	serv_addr.sin_port 			= htons(atoi(*(argv+1)));

	if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("BIND ERROR");
	if (listen(serv_sock, 5) == -1)
		error_handling("LISTEN ERROR");

	while (1) {
		t = localtime(&timer);
		clnt_addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);

		pthread_mutex_lock(&mutx);
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mutx);

		pthread_create(&t_id, NULL, handle_clnt, (void *)&clnt_sock);
		pthread_detach(t_id);
		printf("Connected Client IP : %s ", inet_ntoa(clnt_addr.sin_addr));
		printf("(%d-%d-%d %d:%d)\n", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min);
		printf("chatter (%d/100)\n", clnt_cnt);
	}
	close(serv_sock);
	return 0;
}

void *handle_clnt(void *arg) {
	int clnt_sock = *((int *)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE];

	while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
		send_msg(msg, str_len);

	pthread_mutex_lock(&mutx);
	for (i = 0; i < clnt_cnt; i++) {
		if (clnt_sock == clnt_socks[i]) {
			while (i++ < clnt_cnt - 1)
				clnt_socks[i] = clnt_socks[i+1];
			break;
		}
	}
	clnt_cnt--;
	pthread_mutex_unlock(&mutx);
	close(clnt_sock);
	return NULL;
}

void send_msg(char *msg, int len) {
	int i;
	pthread_mutex_lock(&mutx);
	for (i = 0; i < clnt_cnt; i++)
		write(clnt_socks[i], msg, len);
	pthread_mutex_unlock(&mutx);
}

void error_handling(char *msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

char *server_state(int count) {
	if (count < 5)
		return "Good";
	else
		return "Bad";
}

void menu(char *port) {
	system("clear");
	printf("SERVER PORT    : %s\n", port);
	printf("SERVER STATE   : %s\n", server_state(clnt_cnt));
	printf("MAX CONNECTION : %d\n", MAX_CLNT);
	printf("****\t\tLog\t\t****\n\n");
}
