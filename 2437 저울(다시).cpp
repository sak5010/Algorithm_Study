/*
	1 1 2 3 6 7 22 30 >> 22�� 1~7������ ���� ��+1���� ũ�Ƿ� 21ǥ��X 
	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
	������ ������ ���� �տ��� ���� ���� ��C + 1�� ���� �۰ų� ������ 
	�� ������ ���� ������ ���� ��� ���� ǥ���� �� �ִ�.
	��, �������� ���� ��
	i+1�� ���� i������ ���� ��+1���� ũ�ٸ� 
	������ +1�� +1�� �ּҰ� �̴�. 
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
