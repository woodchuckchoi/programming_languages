#include <stdio.h>
#include <string.h>

union Data {
	int i;
	float f;
	char str[20];
};

int main() {
	union Data tmp;

	tmp.i = 10;
	printf("I:%d F:%f STR:%s\n", tmp.i, tmp.f, tmp.str);
	tmp.f = 200.5;
	printf("I:%d F:%f STR:%s\n", tmp.i, tmp.f, tmp.str);
	strcpy(tmp.str, "C programming");
	printf("I:%d F:%f STR:%s\n", tmp.i, tmp.f, tmp.str);
	return 0;
}
