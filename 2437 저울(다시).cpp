/*
	1 1 2 3 6 7 22 30 >> 22가 1~7까지의 누적 값+1보다 크므로 21표현X 
	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
	다음에 나오는 값이 앞에서 부터 누적 값C + 1값 보다 작거나 같으면 
	그 값까지 더한 누적값 까지 모든 수를 표현할 수 있다.
	즉, 오름차순 정렬 후
	i+1의 값이 i까지의 누적 값+1보다 크다면 
	누적값 +1의 +1이 최소값 이다. 
*/
#include <stdio.h>
#include <algorithm>

int d[1001];

int main(void) {
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; ++i) {
		int a;
		scanf("%d", &a);
		d[i] = a;
	}
	std::sort(d, d+N);
	int accum = 1;
	for(int i=0; i<N; ++i) {
		if(accum < d[i]) break;
		accum += d[i];
	}
	printf("%d", accum);
		
	return 0;
}
