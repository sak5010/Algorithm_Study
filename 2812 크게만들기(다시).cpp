/*
	198794
	앞에서 부터 스택에 데이터를 넣고
	다음에 들어오는 값이 top에 있는 값보다 크면
	바꿔서 넣는다. 이때 지우는 동작을 하므로 k--
	이때 내림차순으로 나오다가 갑자기 큰 수가 나오면
	하나만 바꾸는 거로는 최대값을 유지할 수 없으므로
	다음에 들어갈 수 보다 작은 놈은 top에서 계속 pop 해준다. k--
	그리고 같거나 큰놈을 만나면 넣는다. 
	이런식으로 숫자의 개수만큼 반복시켜주면 된다.
	아직도 지워야할 k가 남아있는 경우
	k의 수 만큼 스택에서 pop해주면 된다.
	왜냐하면 스택에는 내림차순으로 들어가 있기 때문에
	top에는 가장 작은 수가 올라와 있기 때문이다. 
	// 이 문제를 풀때 여러 테스트 케이스를 생각하는 능력이
	부족해서 고생했던 기억이 있다.
	여러 테스트 케이스를 생각해내는 능력도 길러야 한다는
	고우람 조교님 말씀이 기억난다. 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	vector<char> stack;
	int n, k;
	string s;
	cin >> n >> k >> s;
	
	for(int i=0; i<n; ++i) {
		while(!stack.empty() && k > 0 && stack.back() < s[i]) {
			stack.pop_back();
			--k;
		}
		stack.push_back(s[i]);
	}
	while(k > 0) {
		stack.pop_back();
		--k;
	}
	for(size_t i=0; i<stack.size(); ++i) {
		cout << stack[i];
	}
		
	return 0;
}
