/*
	��������(merge sort)�� �����İ� �����ϰ� O(N*logN)�̸�, �̸� �����Ѵ�.
	�������� ��յ��ϰ� ���ҵ� ��� �־��� ���� O(N^2)�� ���� �� ������,
	���������� �׻� �յ��ϰ� �� ������ ������ ������ O(N*logN)�� �����Ѵ�.
	������, �߰����� �迭 ������ �ʿ��ϱ� ������ �޸� ȿ������ ���ٰ� �� �� �ִ�. 
*/

#include <stdio.h>

int number = 8;
int sorted[8]; // ���������� ������ �ӽ� ���İ����� �ʿ��ϴ�. 

void merge(int* a, int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	while(i <= middle && j <= n) { // �κ������� ����. 
		if(a[i] <= a[j]) {
			sorted[k] = a[i];
			++i;
		} else {
			sorted[k] = a[j];
			++j;
		}
		++k;
	} // ���⼭ ���������� ���� ���� �����ʸ� �����Ͱ� ��������. �־������. 
	if(i > middle) { // ������ �����͸� �����ִ� ��� 
		for(int t=j; t<=n; ++t) {
			sorted[k] = a[t];
			++k;
		}
	} else {
		for(int t=i; t<=middle; ++t) {
			sorted[k] = a[t];
			++k;
		}
	} // ���� ���������� ���� �迭�� �����͸� ��������� ��. 
	for(int t=m; t<=n; ++t) {
		a[t] = sorted[t];
	}
}

void merge_sort(int* a, int m, int n) {
	if(m < n) {
		int middle = (m + n) / 2;
		merge_sort(a, m, middle);
		merge_sort(a, middle+1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {
	int array[number] = { 7, 6, 5, 8, 3, 5, 9, 1 };
	merge_sort(array, 0, number-1);
	for(int i=0; i<number; ++i)
		printf("%d ", array[i]);	
	return 0;
}
