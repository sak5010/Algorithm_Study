/*
	추들의 무게가 주어지면 각 추들을 조합해서 측정할 수 있는
	무게 중 측정할 수 없는 무게의 최소값을 구하는 문제다.
	이 문제는 추들을 오름차순으로 정렬하고
	앞에서 부터 누적 값이 다음 값보다 작다면 그 누적 값과
	다음 값 사이의 무게는 측정할 수 없는 것이다.
	i) 추들을 오름차순으로 정렬한다.
	ii) 1부터 측정할 수 있는지 검사해야 하므로 
	    accum = 1;로 설정해 두고
		앞에서 부터 순서대로의 인덱스 값과 비교하여
		그 인덱스 값 보다 accum 값이 크거나 같으면 
		accum += 인덱스 값을 해준다.
		그렇지 않으면 accum값을 그대로 출력해준다. 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int w[1001];

int main(void) {
	int N, a;
	cin >> N;
	
	for(int i=0; i<N; ++i) {
		cin >> a;
		w[i] = a;
	}
	
	sort(w, w+N);
	
	int accum = 1; // 누적 값 바로 다음 값을 출력 못할것 이므로. 
	for(int i=0; i<N; ++i) {
		if(accum < w[i]) break;
		accum += w[i]; 
	}
	cout << accum;
	
	return 0;
}
