/*
	ó���� ����� �״�� ���ϸ� �ǰ�
	-��ȣ�� ������ �� �� �� �� ������
	��ȣ�� ������� ��� ���� ó���ϸ� �ּҰ��� ���´�. 
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
