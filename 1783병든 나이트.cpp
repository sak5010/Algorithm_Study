/*
	N == 1�̸� 1ĭ
	N == 2�̸� 
	X X O X X X O X X X
	O X X X O X X X X X
	4���� �Ѱ�. M>=7 ���� ��� 4��. 
	M<7 ���� (M+1)/2��.
	N >= 3�� ��쿡
	X O X O X X X X X X X X X X
	X X X X X X X X X X X X X X
	O X O X X X X X X X X X X X
	M<=4�϶��� M��. 
	
	X O X X X X X O X O X O X O
	X X X X O X X X X X X X X X
	O X O X X X O X O X O X O X
	M>4�϶��� 
	M==5 : 4
	M==6 : 4
	M==7 : 5
	M==8 : 6
	M==9 : 7
	�� M-2���� 4�� �� �ִ밪�� ������ �ȴ�. 
*/

#include <stdio.h>
#include <algorithm>

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	
	if(N == 1) printf("%d", 1);
	else if(N == 2) {
		if(M < 7) {
			printf("%d", (M+1)/2);
		}
		else {
			printf("%d", 4);
		}
	}
	else {
		if(M <= 4) {
			printf("%d", M);
		}
		else {
			printf("%d", std::max(4, M-2));
		}
	}
	
	return 0;
}
