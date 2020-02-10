/*
	quick sort는 대표적인 분할정복 알고리즘으로 평균속도가 
	O(N*logN)으로 빠른 알고리즘이다.
	하지만 이미 거의 정렬이 되어 있는 경우 최악 O(N^2) 이다. 
	하나의 큰 문제를 두 개의 작은 문제로 계속 분할하여 정렬 한 뒤
	합치는 방식이다.
	특정한 값을 기준으로 큰 숫자와 작은 숫자로 서로 교환한 뒤에
	배열을 반으로 나눈다.
	퀵 정렬에는 기준 값이 있는데 피벗(Pivot)이라고도 한다.
	보통 첫 번째 원소를 피벗 값으로 설정하고 사용한다.
	(1) 10 5 8 7 6 4 3 2 9 
	처음 첫 번째 값인 1이 피벗 값으로 설정이 된다. 
	이 경우 1보다 큰 숫자를 왼쪽 부터 찾고, 1보다 작은 숫자를
	오른쪽 부터 찾는다. 이 때 작은 값의 인덱스가 큰 값의 인덱스보다
	작으면 피벗 값과 작은 값의 위치를 바꾼다. 
	즉, 둘 다 찾으면 그 두개 교환, 엇갈리면 피벗과 작은 값 교환. 
	이렇게 하면 피벗값의 왼쪽에는 피벗 값 보다 작은 값이 위치하고
	오른쪽에는 피벗 값보다 큰 값이 위치하게 된다. 
	그 피벗값을 기준으로 왼쪽을 퀵정렬, 오른쪽을 퀵정렬 따로 해준다. 
*/

#include <stdio.h>

#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void quick_sort(int* array, int start, int end) {
	if(start >= end) { // 비교 영역이 0이나 1일때 
		return;
	}
	int pivot = start; // 여기서는 맨 왼쪽 데이터를 pivot으로 설정. 
	int left = start + 1;
	int right = end;
	while(left <= right) { // 엇갈릴때 까지 반복. 
		while(array[left] <= array[pivot]) { // 왼쪽 부터 pivot값 보다 큰 값 찾음. 
			++left;
		}
		while(right > start && array[right] >= array[pivot]) { // 오른쪽 부터 pivot값 보다 작은 값 찾음. 
			--right; // pivot값과 작은 값을 바꿔야 하므로 작은 값의 위치가 start 위치보다 오른쪽에 오도록 제한한다. 
		}
		if(left > right) { // 엇갈리면 pivot과 작은 값 교체. 
			int temp;
			SWAP(array[pivot], array[right], temp);
		} else { // 엇갈리지 않았으면 작은 값과 큰 값 교체. 
			int temp;
			SWAP(array[left], array[right], temp);
		}
	} // 피벗 기준 왼쪽 오른쪽 각각 재귀호출. 
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
