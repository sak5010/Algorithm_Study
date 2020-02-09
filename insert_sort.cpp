/*
	insert sort는 O(N^2)으로 selection sort나 bubble sort와 같은
	시간복잡도를 가지지만, 일반적으로 좀 더 빠르다.
	왜냐하면 알고리즘 과정에서 특정 부분 부터는 이미 정렬되어
	있다고 가정하기 때문에 끝까지 가지 않기 때문이다.
	예를들어, { 2, 3, 4, 5, 6, 1 }이라는 배열을 정렬할때
	6까지는 이미 정렬이 되어 있기 때문에 별 다른 연산 없이
	쭉 6까지 다이렉트로 가게 된다. 그 후 1을 봤을때 왼쪽의 
	값이 1보다 크기 때문에 왼쪽으로 가면서 정렬하게 된다.
	이렇게 거의 정렬이 되어 있는 경우 bubble sort는 매우
	강력한 성능을 보여준다.(데이터도 적게 먹고 속도도 빠르다.) 
*/
#include <stdio.h>

void insert_sort(int a[]) {
	for(int i=0; i<9; ++i) { // 주의.마지막에 a[9] > a[10] 비교하게 됨. 
		int j=i, temp;
		while(j>=0 && a[j] > a[j+1]) {
			temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
			--j;
		}
	}
}

void print_out(int a[]) {
	for(int i=0; i<10; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void) {
	int a[10] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 1 };
	
	insert_sort(a);
	print_out(a);
	
	return 0;
}
