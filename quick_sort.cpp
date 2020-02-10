/*
	quick sort�� ��ǥ���� �������� �˰������� ��ռӵ��� 
	O(N*logN)���� ���� �˰����̴�.
	������ �̹� ���� ������ �Ǿ� �ִ� ��� �־� O(N^2) �̴�. 
	�ϳ��� ū ������ �� ���� ���� ������ ��� �����Ͽ� ���� �� ��
	��ġ�� ����̴�.
	Ư���� ���� �������� ū ���ڿ� ���� ���ڷ� ���� ��ȯ�� �ڿ�
	�迭�� ������ ������.
	�� ���Ŀ��� ���� ���� �ִµ� �ǹ�(Pivot)�̶�� �Ѵ�.
	���� ù ��° ���Ҹ� �ǹ� ������ �����ϰ� ����Ѵ�.
	(1) 10 5 8 7 6 4 3 2 9 
	ó�� ù ��° ���� 1�� �ǹ� ������ ������ �ȴ�. 
	�� ��� 1���� ū ���ڸ� ���� ���� ã��, 1���� ���� ���ڸ�
	������ ���� ã�´�. �� �� ���� ���� �ε����� ū ���� �ε�������
	������ �ǹ� ���� ���� ���� ��ġ�� �ٲ۴�. 
	��, �� �� ã���� �� �ΰ� ��ȯ, �������� �ǹ��� ���� �� ��ȯ. 
	�̷��� �ϸ� �ǹ����� ���ʿ��� �ǹ� �� ���� ���� ���� ��ġ�ϰ�
	�����ʿ��� �ǹ� ������ ū ���� ��ġ�ϰ� �ȴ�. 
	�� �ǹ����� �������� ������ ������, �������� ������ ���� ���ش�. 
*/

#include <stdio.h>

#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void quick_sort(int* array, int start, int end) {
	if(start >= end) { // �� ������ 0�̳� 1�϶� 
		return;
	}
	int pivot = start; // ���⼭�� �� ���� �����͸� pivot���� ����. 
	int left = start + 1;
	int right = end;
	while(left <= right) { // �������� ���� �ݺ�. 
		while(array[left] <= array[pivot]) { // ���� ���� pivot�� ���� ū �� ã��. 
			++left;
		}
		while(right > start && array[right] >= array[pivot]) { // ������ ���� pivot�� ���� ���� �� ã��. 
			--right; // pivot���� ���� ���� �ٲ�� �ϹǷ� ���� ���� ��ġ�� start ��ġ���� �����ʿ� ������ �����Ѵ�. 
		}
		if(left > right) { // �������� pivot�� ���� �� ��ü. 
			int temp;
			SWAP(array[pivot], array[right], temp);
		} else { // �������� �ʾ����� ���� ���� ū �� ��ü. 
			int temp;
			SWAP(array[left], array[right], temp);
		}
	} // �ǹ� ���� ���� ������ ���� ���ȣ��. 
	quick_sort(array, start, right-1);
	quick_sort(array, right+1, end);
}

void print_out(int* array, int s, int e) {
	for(int i=s; i<e; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

int main(void) {
	
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	quick_sort(array, 0, 9);
	print_out(array, 0, 10);
	
	return 0;	
}
