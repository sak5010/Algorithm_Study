/*
	bubble sort�� selection sort�� ���� O(N^2)���� ��ȿ������
	���ľ˰��� �̴�. ������ selection sort���� �� ������,
	�� ������ selection sort�� �ݺ��� ����� �� �� ������ �� 
	������ �� �˻� �� �� ������ ��ü ������ �����ϴ� �ݸ�
	bubble sort�� �Ź� ��ü������ �����ϱ� �����̴�.
	����, bubble sort�� ���� �����ϱ� ���� ���� �˰�����
	���ÿ� ���� ��ȿ������ ���� �˰����̴�. 
*/

#include <stdio.h>
using namespace std;

void bubble_sort(int array[]) {
	int temp;
	for(int i=0; i<10; ++i) {
		for(int j=0; j<9-i; ++j) {
			if(array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void print_out(int array[]) {
	for(int i=0; i<10; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

int main(void) {
	int array[10] = { 2, 6, 1, 10, 9, 4, 5, 3, 8, 7 };
	
	bubble_sort(array);
	print_out(array);
	
	return 0;
}
