#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

constexpr int MAX_C = 5001;
constexpr int MAX_M = 10001;

pair<int, int> price[MAX_C]; // 사탕의 종류와 가격표. 
int dp[MAX_M]; // 잔액을 저장할 cache. 
int N; // 사탕 종류의 수. 

int candy(int money) {
	if(money == 0) return 0; // base case. 0원이면 0cal.
	if(dp[money] != -1) return dp[money]; // 검사했었다면 그대로 return. 
	
	int kcal = 0;
	for(int i=0; i<N; ++i) { // candy의 종류 만큼 모든 경우 알아보기. 
		if(money - price[i].second >= 0) // 잔액이 부족하지 않으면, 
			kcal = max(kcal, candy(money - price[i].second) // 남은 잔액에서 재귀. 
					+ price[i].first); // 금액 지불 했으니 cal 증가. 
	}
	dp[money] = kcal; // 검사 끝났으면 cache에 기록.
	return kcal;
}

int main(void) {
	while(true) {
		double M, p;
		int c;
		cin >> N >> M;
		if(N == 0 && M == 0.0) break;
		for(int i=0; i<N; ++i) { // 사탕 목록 입력. 
			cin >> c >> p;
			price[i] = make_pair(c, (int)(p*100+0.5)); // 정수 변환, 반올림. 
		}
		fill(dp, dp+MAX_M, -1); // 검사하지 않은 경우 -1. 
		cout << candy((int)(M*100+0.5)) << endl;
	}
	return 0;
}
