#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<string, pair<int, int> >& a, 
			const pair<string, pair<int, int> >& b) {
	if(a.second.first == b.second.first)
		return a.second.second > b.second.second;
	else
		return a.second.first > b.second.first;
}

int main(void) {
	vector<pair<string, pair<int, int> > > v;
	v.push_back(pair<string, pair<int, int> >("김상현", pair<int, int>(85, 19941114)));
	v.push_back(pair<string, pair<int, int> >("고선아", pair<int, int>(95, 19980924)));
	v.push_back(pair<string, pair<int, int> >("박성국", pair<int, int>(95, 19950821)));
	v.push_back(pair<string, pair<int, int> >("장수현", pair<int, int>(88, 19970724)));
	v.push_back(pair<string, pair<int, int> >("장윤수", pair<int, int>(96, 19970724)));
	
	sort(v.begin(), v.end(), compare);
	
	for(int i=0; i<v.size(); ++i)
		cout << v[i].first << ' ';
	return 0;
}
