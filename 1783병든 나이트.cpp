/*
	N == 1이면 1칸
	N == 2이면 
	X X O X X X O X X X
	O X X X O X X X X X
	4개가 한계. M>=7 부터 계속 4개. 
	M<7 부터 (M+1)/2개.
	N >= 3인 경우에
	X O X O X X X X X X X X X X
	X X X X X X X X X X X X X X
	O X O X X X X X X X X X X X
	M<=4일때는 M개. 
	
	X O X X X X X O X O X O X O
	X X X X O X X X X X X X X X
	O X O X X X O X O X O X O X
	M>4일때는 
	M==5 : 4
	M==6 : 4
	M==7 : 5
	M==8 : 6
	M==9 : 7
	즉 M-2개와 4개 중 최대값을 넣으면 된다. 
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
