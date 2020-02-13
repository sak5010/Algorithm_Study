#include <stdio.h>

int number = 9;
int heap[9] = { 5, 2, 1, 10, 8, 9, 7, 6, 0 };

int main(void) {
	// ���� ����
	for(int i=1; i<number; ++i) {
		int c = i;
		do {
			int p = (c - 1) / 2;
			if(heap[p] < heap[c]) {
				int temp = heap[p];
				heap[p] = heap[c];
				heap[c] = temp;
			}
			c = p;
		} while(c != 0);
	}
	// ���� �ٿ����� �ݺ������� ���� ����
	for(int i=number - 1; i>=0; --i) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int c, p=0;
		do {
			c = p * 2 + 1;
			if(c < i-1 && heap[c] < heap[c+1])
				++c;
			if(c < i && heap[p] < heap[c]) {
				temp = heap[p];
				heap[p] = heap[c];
				heap[c] = temp;
			}
			p = c;
		} while(c < i);
	}
	for(int i=0; i<number; ++i)
		printf("%d ", heap[i]);
		
	return 0;
}
