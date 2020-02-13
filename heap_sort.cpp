/*
	i) 힙을 구성한다. (상향, 하향 상관 X) 
	ii) 맨 위에 있는 값과 마지막 값을 교환하며 뒤에서부터 하나씩 정렬한다. 
	즉, O(N*logN)의 시간복잡도를 보장한다. 
*/
#include <stdio.h>

int number = 9;
int heap[9] = { 5, 6, 2, 1, 3, 9, 8, 7, 10 };

int main(void) {
	// i) 힙을 구성한다.
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
	// ii) 하나씩 빼가며 힙을 구성한다.
	for(int i=number -1; i>=0; --i) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int c, p = 0;
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
