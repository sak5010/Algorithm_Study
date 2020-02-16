/*
	A등수와 B등수 둘 중 하나라도
	다른 지원자들 보다 점수가 높아야 한다.
	A등수에 대해서 오름차순 정렬하면 A의 순위대로 정렬된다.
	맨 위에 있는 사람은 A등수가 1등이므로 A점수에 대해서는
	자기보다 뛰어난 사람이 없으므로 합격이다.
	A점수가 2등인 사람은 자기보다 A점수가 높은 1등과 비교해서
	B등수가 더 높으면 그 사람도 합격이다.
	즉, A등수를 기준으로 자기보다 높은 등수에 있는 사람 보다
	B등수가 앞선 사람만이 합격할 수 있는 것이다.
	따라서, 해결방법은
	i) A등수를 기준으로 오름차순 정렬한다.
	ii) i(0~N-1)번째 지원자의 B등수를 최소값에 갱신하고
		(해당 지원자의 B등수가 현재 최소값 보다 더 작다면) 
	    합격 인원을 1명 증가시킨다. 
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int employment(vector<pair <int, int> >& v) {
	sort(v.begin(), v.end());
	int min = 100001, candidates = 0;
	for(size_t i=0; i<v.size(); ++i) {
		if(v[i].second < min) {
			min = v[i].second;
			++candidates;
		}
	}
	return candidates;
}

int main(void) {
	vector<pair <int, int> > v;
	
	int T, N, a, b;
	cin >> T;
	for(int i=0; i<T; ++i) {
		cin >> N;
		for(int j=0; j<N; ++j) {
			cin >> a >> b;
			v.push_back(make_pair(a,b));
		}
		cout << employment(v);
		v.clear();
	}

	return 0;
}
