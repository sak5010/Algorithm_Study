#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 100000;
int N;

int dp[MAX][3]; // ¿À¸¥ÂÊÀÌ 0: Àü¿¡ ¾È¶«. 1: À§ ¶«. 2: ¾Æ·¡ ¶«. 
int value[2][MAX];

int sticker(int c, int status) {
	if(c == N) return 0;
	if(dp[c][status] != -1) return dp[c][status];
	
	int result = sticker(c+1, 0);
	if(status != 1) result = max(result, sticker(c+1, 1) + value[0][c]);
	if(status != 2) result = max(result, sticker(c+1, 2) + value[1][c]);
	dp[c][status] = result;
	
	return result;
}

int main(void) {
	int T;
	cin >> T;
	for(int t=0; t<T; ++t) {
		cin >> N;
		for(int i=0; i<2; ++i)// Input
			for(int j=0; j<N; ++j)
				cin >> value[i][j];
		for(int i=0; i<N; ++i) // dp ÃÊ±âÈ­. 
			for(int j=0; j<3; ++j)
				dp[i][j] = -1;
			
		cout << sticker(0, 0) << endl;
	}
	return 0;
}
