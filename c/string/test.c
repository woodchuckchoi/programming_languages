#include <stdio.h>

char cmpString(char *a, char *b) {
    while (*a != 0 && *b != 0) {
        if (*a == *b) {
            ++a;
            ++b;
        } else {
            return 0;
        }
    }
    if (*a != 0 || *b != 0) {
        return 0;
    }
    return 1;
}

int main() {
	printf("%p\n", "test");

	char *a = "test";
	char *b = "test";
	char *c = "test ";
	char *d = "tes";

	printf("a == b: %d\nb == c: %d\nc == d: %d\na == c: %d\n", cmpString(a, b), cmpString(b, c), cmpString(c, d), cmpString(a, c));

	return 0;
}
