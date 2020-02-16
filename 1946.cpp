/*
	A����� B��� �� �� �ϳ���
	�ٸ� �����ڵ� ���� ������ ���ƾ� �Ѵ�.
	A����� ���ؼ� �������� �����ϸ� A�� ������� ���ĵȴ�.
	�� ���� �ִ� ����� A����� 1���̹Ƿ� A������ ���ؼ���
	�ڱ⺸�� �پ ����� �����Ƿ� �հ��̴�.
	A������ 2���� ����� �ڱ⺸�� A������ ���� 1��� ���ؼ�
	B����� �� ������ �� ����� �հ��̴�.
	��, A����� �������� �ڱ⺸�� ���� ����� �ִ� ��� ����
	B����� �ռ� ������� �հ��� �� �ִ� ���̴�.
	����, �ذ�����
	i) A����� �������� �������� �����Ѵ�.
	ii) i(0~N-1)��° �������� B����� �ּҰ��� �����ϰ�
		(�ش� �������� B����� ���� �ּҰ� ���� �� �۴ٸ�) 
	    �հ� �ο��� 1�� ������Ų��. 
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int employment(vector<pair <int, int> >& v) {
	sort(v.begin(), v.end());
	int min = 100001, candidates = 0;
	for(size_t i=0; i<v.size(); ++i) {
		if(v[i].second < min) {
			min = v[i].second;
			++candidates;
		}
	}
	return candidates;
}

int main(void) {
	vector<pair <int, int> > v;
	
	int T, N, a, b;
	cin >> T;
	for(int i=0; i<T; ++i) {
		cin >> N;
		for(int j=0; j<N; ++j) {
			cin >> a >> b;
			v.push_back(make_pair(a,b));
		}
		cout << employment(v);
		v.clear();
	}

	return 0;
}
