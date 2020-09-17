#include <stdio.h>

typedef struct Test {
	int age;
	char *name;
} Test;

int main() {
	Test t;
	t.age = 30;
	t.name = "Hello";
	printf("%s\n%d\n", t.name, t.age);


	return 0;
}
