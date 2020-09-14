#include <stdio.h>
#include <string.h>

struct Book {
	char	title[50];
	char	author[50];
	char	subject[100];
	int	bookId;
};

int main() {
	struct Book Book1;
	struct Book Book2;

	strcpy(Book1.title, "C programming");
	strcpy(Book1.author, "NUha Ali");
	strcpy(Book1.subject, "C Programming Tutorial");
	Book1.bookId = 6495407;

	strcpy(Book2.title, "Telecom Billing");
	strcpy(Book2.author, "Zara Ali");
	strcpy(Book2.subject, "Telecom Billing Tutorial");
	Book2.bookId = 6495700;

	struct Book ex[2] = {Book1, Book2};

	int i;
	for (i = 0; i < sizeof(ex)/sizeof(*ex); i++) {
		printf("%50s %50s %100s %10d\n", ex[i].title, ex[i].author, ex[i].subject, ex[i].bookId);
	}
	return 0;
}
