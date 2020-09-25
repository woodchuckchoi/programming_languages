#include <stdio.h>
#include "func.h"

static void test() {
	printf("static void func");
}

void test2() {
	printf("another file, not static\n");
}
