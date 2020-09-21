#include <stdio.h>
#include <stdlib.h>
#include "swap.h"

typedef struct Heap {
	int *data;
	int size;
} Heap;

void heapify(Heap *heap, int i) {
	int left = 2*i+1;
	int right = 2*i+2;
	int smallest = i;

	if (left < heap->size && *((heap->data)+left) < *((heap->data)+smallest)) {
		smallest = left;
	}
	if (right < heap->size && *((heap->data)+right) < *((heap->data)+smallest)) {
		smallest = right;
	}

	if (smallest != i) {
		swap(heap->data, smallest, i);
		heapify(heap, smallest);
	}
}

void heap_sort(Heap *heap) {
	for (int i = heap->size/2; i > -1; i--) {
		heapify(heap, i);
	}

	for (int i = heap->size-1; i > -1; i--) {
		swap(heap->data, 0, i);
		printf("%d ", *((heap->data)+i));
		heap->size--;
		heapify(heap, 0);
	}
	printf("\n");
}

int main() {
	Heap h;
	int data[] = {432,5343,634,7,34,756,4,74,534,687,53,68,354,59,523,7};
	h.data = data;
	h.size = sizeof(data)/sizeof(data[0]);
	heap_sort(&h);
	return 0;
}
