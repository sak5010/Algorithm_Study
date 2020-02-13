#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b) {
	if(a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main(void) {
	int N;
	vector<string> v;
	string s;
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);
	cout << v[0] << endl;
	for(int i=1; i<v.size(); ++i) {
		if(v[i] != v[i-1])
			cout << v[i] << endl;
	}
	return 0;
}
