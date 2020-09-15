#include <stdio.h>

int main() {
	unsigned int b = -1;
	printf("b 에 들어있는 값을 unsigned int 로 해석했을 때 값 : %u \n", b);

	++b;
	printf("b 에 들어있는 값을 unsigned int 로 해석했을 때 값 : %u \n", b);
	
	return 0;
}
