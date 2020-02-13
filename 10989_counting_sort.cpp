#include <stdio.h>

int a[10001];
int N;

int main(void) {
	scanf("%d", &N);
	for(int i=0; i<N; ++i) {
		int x;
		scanf("%d", &x);
		++a[x];
	}
	for(int i=1; i<=10000; ++i) {
		while(a[i] != 0) {
			printf("%d\n", i);
			--a[i];
		}
	}
	return 0;
}
