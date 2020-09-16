#include <stdio.h>

struct Test {
	int age;
	char *name;
};

int main() {
	struct Test t1, t2;
	
	t1.age = 30;
	t1.name = "Test Name";

	t2 = t1;

	struct Test *pt = &t2;

	pt->age = 5;

	printf("Name: %s\nAge: %d", t2.name, t2.age);

	return 0;
}
