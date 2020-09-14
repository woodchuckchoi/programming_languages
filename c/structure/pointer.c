#include <stdio.h>
#include <string.h>

struct Book {
	char	title[50];
	char	author[50];
	char	subject[50];
	int	book_id;
};

void printBook(struct Book *book);
int main() {
	struct Book book1;
	struct Book book2;

	strcpy( book1.title, "C Programming");
	strcpy( book1.author, "Nuha Ali"); 
	strcpy( book1.subject, "C Programming Tutorial");
	book1.book_id = 6495407;

	/* book 2 specification */
	strcpy( book2.title, "Telecom Billing");
	strcpy( book2.author, "Zara Ali");
	strcpy( book2.subject, "Telecom Billing Tutorial");
	book2.book_id = 6495700;

	printBook(&book1);
	printBook(&book2);

	return 0;
}

void printBook(struct Book *book) {
	printf("%50s %50s %100s %d\n", book->title, book->author, book->subject, book->book_id);
}
