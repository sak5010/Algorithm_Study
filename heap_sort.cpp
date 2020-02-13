/*
	i) ���� �����Ѵ�. (����, ���� ��� X) 
	ii) �� ���� �ִ� ���� ������ ���� ��ȯ�ϸ� �ڿ������� �ϳ��� �����Ѵ�. 
	��, O(N*logN)�� �ð����⵵�� �����Ѵ�. 
*/
#include <stdio.h>

int number = 9;
int heap[9] = { 5, 6, 2, 1, 3, 9, 8, 7, 10 };

int main(void) {
	// i) ���� �����Ѵ�.
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
	// ii) �ϳ��� ������ ���� �����Ѵ�.
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
