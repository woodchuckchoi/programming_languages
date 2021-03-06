#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <time.h>

#define BUF_SIZE 100
#define NORMAL_SIZE 20

void *send_msg(void *arg);
void *recv_msg(void *arg);
void error_handling(char *msg);

void menu();
void change_name();
void menu_options();

char name[NORMAL_SIZE] = "[DEFAULT]";
char msg_form[NORMAL_SIZE];
char serv_time[NORMAL_SIZE];
char msg[BUF_SIZE];
char serv_port[NORMAL_SIZE];
char clnt_ip[NORMAL_SIZE];

int main(int argc, char **argv) {
	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void *thread_return;

	if (argc != 4)
		error_handling("PARAMETER ERROR");

	struct tm *t;
	time_t timer = time(NULL);
	t = localtime(&timer);
	sprintf(serv_time, "%d-%d-%d %d:%d", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min);
	
	sprintf(name, "[%s]", *(argv+3));
	sprintf(clnt_ip, "%s", *(argv+1));
	sprintf(serv_port, "%s", *(argv+2));
	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(*(argv+1));
	serv_addr.sin_port=htons(atoi(*(argv+2)));

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("CONNECT ERROR");

	menu();

	pthread_create(&snd_thread, NULL, send_msg, (void *)&sock);
	pthread_create(&rcv_thread, NULL, recv_msg, (void *)&sock);
	pthread_join(snd_thread, &thread_return);
	pthread_join(rcv_thread, &thread_return);
	close(sock);
	return 0;
}

void *send_msg(void *arg) {
	int sock = *((int *)arg);
	char name_msg[NORMAL_SIZE+BUF_SIZE];
	char my_info[BUF_SIZE];
	char *who = NULL;
	char temp[BUF_SIZE];

	printf(" >> join the chat !! \n");
	sprintf(my_info, "%s's joined. IP_%s\n", name, clnt_ip);
	write(sock, my_info, strlen(my_info));

	while (1) {
		fgets(msg, BUF_SIZE, stdin);

		if (!strcmp(msg, "!menu\n")) {
			menu_options();
			continue;
		}

		else if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) {
			close(sock);
			exit(0);
		}

		sprintf(name_msg, "%s %s", name, msg);
		write(sock, name_msg, strlen(name_msg));
	}
	return NULL;
}

void *recv_msg(void *arg) {
	int sock = *((int *)arg);
	char name_msg[NORMAL_SIZE+BUF_SIZE];
	int str_len;

	while (1) {
		str_len = read(sock, name_msg, NORMAL_SIZE+BUF_SIZE-1);
		if (str_len == -1)
			return (void *)-1;
		name_msg[str_len] = 0;
		fputs(name_msg, stdout);
	}
	return NULL;
}

void menu_options() {
	int select;
	printf("\n\t**** menu mode ****\n");
    printf("\t1. change name\n");
    printf("\t2. clear/update\n\n");
    printf("\tthe other key to cancel");
    printf("\n\t*******************");
    printf("\n\t>> ");
    scanf("%d", &select);
	getchar();

	switch(select) {
		case 1:
			change_name();
			break;

		case 2:
			menu();
			break;

		default:
			printf("\tcancel");
			break;
	}
}

void change_name() {
	char name_temp[100];
	printf("\n\tInput new name -> ");
	scanf("%s", name_temp);
	sprintf(name, "[%s]", name_temp);
	printf("\n\tComplete\n\n");
}

void menu() {
	system("clear");
	printf(" **** moon/sum chatting client ****\n");
    printf(" server port : %s \n", serv_port);
    printf(" client IP   : %s \n", clnt_ip);
    printf(" chat name   : %s \n", name);
    printf(" server time : %s \n", serv_time);
    printf(" ************* menu ***************\n");
    printf(" if you want to select menu -> !menu\n");
    printf(" 1. change name\n");
    printf(" 2. clear/update\n");
    printf(" **********************************\n");
    printf(" Exit -> q & Q\n\n");
}

void error_handling(char *msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
