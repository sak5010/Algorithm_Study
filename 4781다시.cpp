#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

constexpr int MAX_C = 5001;
constexpr int MAX_M = 10001;

pair<int, int> price[MAX_C]; // ������ ������ ����ǥ. 
int dp[MAX_M]; // �ܾ��� ������ cache. 
int N; // ���� ������ ��. 

int candy(int money) {
	if(money == 0) return 0; // base case. 0���̸� 0cal.
	if(dp[money] != -1) return dp[money]; // �˻��߾��ٸ� �״�� return. 
	
	int kcal = 0;
	for(int i=0; i<N; ++i) { // candy�� ���� ��ŭ ��� ��� �˾ƺ���. 
		if(money - price[i].second >= 0) // �ܾ��� �������� ������, 
			kcal = max(kcal, candy(money - price[i].second) // ���� �ܾ׿��� ���. 
					+ price[i].first); // �ݾ� ���� ������ cal ����. 
	}
	dp[money] = kcal; // �˻� �������� cache�� ���.
	return kcal;
}

int main(void) {
	while(true) {
		double M, p;
		int c;
		cin >> N >> M;
		if(N == 0 && M == 0.0) break;
		for(int i=0; i<N; ++i) { // ���� ��� �Է�. 
			cin >> c >> p;
			price[i] = make_pair(c, (int)(p*100+0.5)); // ���� ��ȯ, �ݿø�. 
		}
		fill(dp, dp+MAX_M, -1); // �˻����� ���� ��� -1. 
		cout << candy((int)(M*100+0.5)) << endl;
	}
	return 0;
}
