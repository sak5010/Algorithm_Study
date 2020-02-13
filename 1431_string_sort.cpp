#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int sum(string a) {
	int s = 0;
	for(int i=0; i<a.length(); ++i) {
		if(a[i] - '0' >= 0 && a[i] - '0' <=9)
			s += a[i] - '0';
	}
	return s;
}

bool compare(string a, string b) {
	if(a.length() != b.length()) {
		return a.length() < b.length();
	} else if(sum(a) != sum(b)) {
		return sum(a) < sum(b);
	} else {
		return a < b;
	}
}

int main(void) {
	vector<string> v;
	string s;
	int N;
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<N; ++i)
		cout << v[i] << endl;
	return 0;
}
