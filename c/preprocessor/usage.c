#include <stdio.h>

// # stringifies
#define message_for(a, b) printf(#a " and " #b ": We Love you!\n")

// ## tokenises
#define tokenpaster(n) printf("toke" #n " = %d", token##n)

#if !defined (MESSAGE)
	#define MESSAGE "You Wish!"
#endif

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main() {
	message_for(Carole, Debra);

	int token34 = 40;
	tokenpaster(34);

	printf("Here is the message: %s\n", MESSAGE);

	printf("Max between 20 and 10 is %d\n", MAX(10, 20));
	return 0;
}
