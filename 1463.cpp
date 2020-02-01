#include <iostream>
#include <algorithm>
using namespace std;
constexpr int MAX = 1000001;

int memo[MAX];

int function(int n) {
	if(n == 1) return 0;
	if(memo[n] != -1) return memo[n]; // dp
	
	int result = function(n-1) + 1;
	if(n%2 == 0) result = min(result, function(n/2) + 1);
	if(n%3 == 0) result = min(result, function(n/3) + 1);
	memo[n] = result;
	
	return result;
}

int main(void) {
	int N;
	cin >> N;
	fill(memo, memo+MAX, -1);
	cout << function(N);
	
	return 0;
}
