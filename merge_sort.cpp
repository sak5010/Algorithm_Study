/*
	병합정렬(merge sort)은 퀵정렬과 동일하게 O(N*logN)이며, 이를 보장한다.
	퀵정렬은 비균등하게 분할될 경우 최악의 경우로 O(N^2)이 나올 수 있지만,
	병합정렬은 항상 균등하게 딱 반으로 나누기 때문에 O(N*logN)을 보장한다.
	하지만, 추가적인 배열 공간이 필요하기 때문에 메모리 효율성은 낮다고 할 수 있다. 
*/

#include <stdio.h>

int number = 8;
int sorted[8]; // 병합정렬은 별도의 임시 정렬공간이 필요하다. 

void merge(int* a, int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	while(i <= middle && j <= n) { // 부분집합을 정렬. 
		if(a[i] <= a[j]) {
			sorted[k] = a[i];
			++i;
		} else {
			sorted[k] = a[j];
			++j;
		}
		++k;
	} // 여기서 빠져나오면 왼쪽 도는 오른쪽만 데이터가 남아있음. 넣어줘야함. 
	if(i > middle) { // 오른쪽 데이터만 남아있는 경우 
		for(int t=j; t<=n; ++t) {
			sorted[k] = a[t];
			++k;
		}
	} else {
		for(int t=i; t<=middle; ++t) {
			sorted[k] = a[t];
			++k;
		}
	} // 이제 빠져나오면 실제 배열에 데이터를 삽입해줘야 함. 
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
