#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if(p1.second == p2.second)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}

int main(void) {
	vector< pair<int, int> > v;
	int n, a, b;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end(), compare);
	int count = 0;
	int position = 0;
	for(int i=0; i<n; ++i) {
		if(v[i].first >= position) {
			++count;
			position = v[i].second;
		}
	}
	cout << count;
	return 0;
}
