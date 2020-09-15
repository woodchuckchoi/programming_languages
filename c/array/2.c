#include <stdio.h>

int prime(int n) {
	int idx = 2;
	int lim = n;
	while (idx < lim) {
		if (n % idx == 0) { 
			return 0;
		}
		lim = n / idx;
		++idx;
	}
	return 1;
}

int main() {
	int primes[1000];
	int idx = 0;
	int n = 2;

	while (idx < 1000) {
		while (1) {
			if (prime(n)) {
				primes[idx] = n;
				++n;
				break;
			}
			++n;
		}
		++idx;
	}
	printf("%d", primes[999]);
	return 0;
}
