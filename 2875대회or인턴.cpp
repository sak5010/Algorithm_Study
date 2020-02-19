/*	
	여자 2명 씩
	
	남자 1명 씩
	
	여자: 6명
	남자: 3명
	인턴: 2명
	
	여자 - 남자*2 > 0 이면 그 절대값 수치만큼 여자를 빼면서
	인턴으로 보낸다.(while)
	여자 - 남자*2 < 0 이면 그 절대값 수치만큼 남자를 빼면서
	인턴으로 보낸다.(while)
	아직 들어가야할 인턴이 남아있다면 
	여자 둘, 남자 하나씩 빼가며 인턴을 채운다.(while)
	여자2, 남자1 빼도 0 이상이면 ++ team(while)
*/

#include <stdio.h>

int main(void) {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	while(k > 0 && n - m*2 > 0) {
		--n;
		--k;
	}
	while(k > 0 && n - m*2 < 0) {
		--m;
		--k;
	}
	int a = 1;
	while(k > 0) {
		if(a < 3) {
			--n;
		}
		else {
			--m;
			a = 0;
		}
		--k;
		++a;
	}
	int team = 0;
	while(n-2 >= 0 && m-1 >= 0) {
		n -= 2;
		m -= 1;
		++team;
	}
	printf("%d", team);
	
	return 0;
}
