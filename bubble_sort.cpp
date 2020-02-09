/*
	bubble sort는 selection sort와 같이 O(N^2)으로 비효율적인
	정렬알고리즘 이다. 심지어 selection sort보다 더 느린데,
	그 이유는 selection sort는 반복문 명령을 한 번 수행할 때 
	끝까지 다 검사 후 한 번씩만 교체 연산을 수행하는 반면
	bubble sort는 매번 교체연산을 수행하기 때문이다.
	따라서, bubble sort는 가장 구현하기 쉬운 정렬 알고리즘인
	동시에 가장 비효율적인 정렬 알고리즘이다. 
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
