/*
	������ �ð��� �������� �������� ���� �Ѵ�.
	�̶�, ������ �ð��� ������ ���� �ð��� ���� ������ �����Ѵ�.
	������ �������� ������� a �������� ������ �ð����� 
	b �������� �����ϴ� �ð��� ũ�ų� ������ 
	count++ ���ְ�, ������ �������� ������ �����Ѵ�.
	�̷������� N���� �˻����ָ� �ִ� ������ ������ ���� �� �ִ�. 
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
