#include <iostream>
#include <string>

using namespace std;

int d[11];

int main(void) {
	int n, k, a;
	cin >> n >> k;
	for(int i=0; i<n; ++i) {
		cin >> a;
		d[i] = a;
	}
	int count = 0;
	for(int i=n-1; i>=0; --i) {
		while(k >= d[i]) {
			k -= d[i];
			++count;
		}
	}
	cout << count; 
	return 0;
}
