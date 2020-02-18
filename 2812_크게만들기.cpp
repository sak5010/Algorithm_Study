#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v;
int n, k;
string s;

int main(void) {
	cin >> n >> k >> s;
	for(int i=0; i<n; ++i) {
		while(!v.empty() && k > 0 && v.back() < s[i]-'0') {
			v.pop_back();
			--k;
		}
		v.push_back(s[i]-'0');
	}
	while(k != 0) {
		v.pop_back();
		--k;
	}
	for(size_t i=0; i<v.size(); ++i)
		cout << v[i];
	return 0;
}
