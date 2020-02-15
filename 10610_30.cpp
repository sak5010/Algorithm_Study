/*
	� ���� �ֿ����� �� ���� �� �ڸ����� ���� 3�� ������
	�� ���� 3�� ����̴�.
	���������� 30�� ��� �߿� ���� ū ���� ���ؾ� �ϹǷ�
	�������� �����Ͽ� �� ������ ���ڰ� 0���� Ȯ���ϰ�
	0�̸鼭 �� ������ ���� 3�� ������ �� ���� ���� ū 30�� ����̴�.
	���������� �ԷµǴ� ���ڰ� 10^5���� ���ڱ��� �� �� �����Ƿ�
	�� ���� ������ int�� long long int�� ������ �� ����. (overflow)
	�׷��Ƿ� �Է¹޴� ���� � �� ������ ������ ���� �ƴ϶�
	string ���·�  �Է¹޴°��� ����. 
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	string N;
	cin >> N;
	
	sort(N.begin(), N.end());

	int sumOfNumber = 0;
	for(int i=0; i<N.length(); ++i) {
		sumOfNumber += N[i]-'0';
	}
	
	if(N[0]-'0' == 0 && sumOfNumber%3 == 0) {
		for(int i=N.length()-1; i>=0; --i) {
			cout << N[i];
		}
	}
	else {
		cout << -1;
	}
	
	return 0;
}
