#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h> // epoll_create1(), epoll_ctl(), struct epoll_event
#include <string.h>

#define MAX_EVENTS 5
#define READ_SIZE 10

int main() {
	int running = 1, event_count, i;
	size_t bytes_read;
	char read_buffer[READ_SIZE + 1];

	struct epoll_event event, events[MAX_EVENTS];
	int epoll_fd = epoll_create1(0); // arg 0은 epoll_create()와 같다. epoll instance를 생성한다.

	printf("EPOLL FD: %d\n", epoll_fd);

	if (epoll_fd == -1) {
		fprintf(stderr, "Failed to create epoll file descriptor\n");
		return 1;
	}

	// event는 아래의 epoll_ctl의 3번째 arg인 fd에 대한 정보를 제공한다.
	event.events = EPOLLIN; // EPOLLIN(read) operation을 할 수 있을 때 이벤트를 생성한다.
	event.data.fd = 0;

	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event)) { // epoll_fd epoll instance에 *event와 같은 정보를 지닌 FD 0(stdin)을 추가(EPOLL_CTL_ADD)한다.
		fprintf(stderr, "Failed to add file descriptor to epoll\n");
		close(epoll_fd);
		return 1;
	}

	while (running) {
		printf("\nPolling for input...\n");
		event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, 30000); // epoll_fd instance에서 발생한 이벤트를 (최대 MAX_EVENTS) events에 저장한다. 30000 ms동안 블록한다.
		printf("%d ready events\n", event_count);
		for (i = 0; i < event_count; i++) {
			printf("Reading file descriptor '%d' -- ", events[i].data.fd);
			bytes_read = read(events[i].data.fd, read_buffer, READ_SIZE);
			printf("%zd bytes read.\n", bytes_read);
			read_buffer[bytes_read] = 0;
			printf("Read '%s'\n", read_buffer);

			if (!strncmp(read_buffer, "stop\n", 5))
				running = 0;
		}
	}

	if (close(epoll_fd)) {
		fprintf(stderr, "Failed to close epoll file descriptor\n");
		return 1;
	}
	return 0;
}

