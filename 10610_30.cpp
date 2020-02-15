/*
	어떤 수가 주여지면 그 수의 각 자리수의 합이 3의 배수라면
	그 수는 3의 배수이다.
	문제에서는 30의 배수 중에 가장 큰 값을 구해야 하므로
	내림차순 정렬하여 맨 오른쪽 숫자가 0인지 확인하고
	0이면서 각 숫자의 합이 3의 배수라면 그 수는 가장 큰 30의 배수이다.
	주의할점은 입력되는 숫자가 10^5개의 숫자까지 올 수 있으므로
	이 수를 정수형 int나 long long int에 저장할 수 없다. (overflow)
	그러므로 입력받는 수를 어떤 한 변수에 저장할 것이 아니라
	string 형태로  입력받는것이 좋다. 
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
