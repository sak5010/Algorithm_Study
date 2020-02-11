// 순수한 형태의 퀵정렬로 푸니까 최악의 경우N^2이 나와서 시간초과 걸린듯. 
// sort함수를 써서 풀어보자. 
#include <stdio.h>
#include <algorithm>
#include <array>

#define SWAP(a,b) {int t; t=a; a=b; b=t;}

std::array<int, 1000001> data;

//void quick_sort(int* array, int start, int end) {
//	if(start >= end)
//		return;
//	int pivot = start;
//	int left = pivot + 1;
//	int right = end;
//	int temp;
//	while(left <= right) {
//		while(array[left] <= array[pivot]) {
//			++left;
//		}
//		while(right > pivot && array[right] >= array[pivot]) {
//			--right;
//		}
//		if(left > right) {
//			SWAP(array[pivot], array[right]);
//		} else {
//			SWAP(array[left], array[right]);
//		}
//	}
//	quick_sort(array, start, right-1);
//	quick_sort(array, right+1, end);
//}

int main(void) {
	int N, d;
	scanf("%d", &N);
	for(int i=0; i<N; ++i)
		scanf("%d", &data[i]);
//	quick_sort(data, 0, N-1);
	std::sort(data.begin(), &data.at(N));
	for(int i=0; i<N; ++i)
		printf("%d\n", data[i]);
	return 0;
}
