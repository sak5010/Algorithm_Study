/*
	끝나는 시간을 기준으로 오름차순 정렬 한다.
	이때, 끝나는 시간이 같으면 시작 시간이 빠른 순으로 정렬한다.
	정렬이 끝났으면 순서대로 a 스케줄의 끝나는 시간보다 
	b 스케줄의 시작하는 시간이 크거나 같으면 
	count++ 해주고, 끝나는 지점까지 변수에 저장한다.
	이런식으로 N번만 검사해주면 최대 스케줄 개수를 뽑을 수 있다. 
	1 4
	3 5
 	0 6
	5 7
	3 8
	5 9
	6 10
	8 11
	8 12
	2 13
	12 14
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if(p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second < p2.second;
	}
}

int main(void) {
	int n, a, b;
	vector< pair<int, int> > v;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	
	int count = 1;
	int position = v[0].second;
	for(int i=0; i<n-1; ++i) {
		if(v[i+1].first >= position) {
			position = v[i+1].second;
			++count;
		}
	}
	cout << count;
	return 0;
}
