/*
	처음에 양수는 그대로 더하면 되고
	-기호를 만나는 순 간 그 뒤 수들은
	부호에 관계없이 모두 음수 처리하면 최소값이 나온다. 
*/

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	
	int n = 0, sum = 0;
	bool isMinus = false;
	
	for(int i=0; i<=s.length(); ++i) {
		if(s[i] >= 0x30 && s[i] <= 0x39) {
			n = n*10 + s[i]-'0';
		}
		else if(s[i] == '-') {
			if(isMinus == true) {
				sum += -n;
			}
			else {
				sum += n;
				isMinus = true;
			}
			n = 0;
		} else {
			if(isMinus == true) {
				sum += -n;
			}
			else {
				sum += n;
			}
			n = 0;
		}
	}
	cout << sum;
	
	return 0;
}
