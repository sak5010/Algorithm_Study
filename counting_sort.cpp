/*
	계수정렬(Counting sort)은 범위조건이 있는 경우에 한해서
	즉, 데이터가 한정적일 경우 굉장히 빠른 알고리즘이다.
	O(N)의 속도를 자랑한다. 단, 데이터의 범위가 클 경우
	그만큼 큰 메모리 공간을 낭비해야 한다는 단점이 있다. 
*/
#include <stdio.h>

int main(void) {
	int count[6] = {0, };
	int array[30] = { 1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
					  3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
					  3, 1, 4, 3, 5, 1, 2, 1, 1, 1};
	for(int i=0; i<30; ++i)
		count[array[i]]++;
	for(int i=1; i<=5; ++i) {
		if(count[i] != 0) {
			for(int j=0; j<count[i]; ++j) {
				printf("%d ", i);
			}
		}
	}
	return 0;
}
