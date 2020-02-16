/*
   �� ������ �Ʒ��� Ž���ϸ鼭 A, T, G, C �߿� ���� ���� ���� �����Ѵ�.
   4���� ������ ���� ��� ���ٸ� ���� ������� �ռ� ������ �����Ѵ�.
   �̷��� �ؼ� ���� DNA�� Hamming Distance�� ���� ���� ���� DNA��.
   Hamming Distance�� ���ϴ� ����� ã�� DNA�� �Է¹��� DNA����
   ���� �ϳ� �ϳ� ���� ���鼭 ���� �ٸ� ������ ������������
   Hamming Distance�� ���� ++ ���ָ� �ȴ�.
   Ž���� ��� ������ Hamming Distance�� ���� ã�� �� �ִ�. 
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using namespace std;

bool compare(const pair<char, int>& a, const pair<char, int>& b) {
   if(a.second == b.second) { // ���� �󵵼��� ������ ������ ����. 
      return a.first < b.first;
   }
   else { // �ٸ��� �󵵼� �������� ����. 
      return a.second > b.second;
   }
}

void refresh(vector< pair<char, int> >& DNAs) {
	DNAs.clear();
	DNAs.push_back(make_pair('A', 0));
   	DNAs.push_back(make_pair('C', 0));
   	DNAs.push_back(make_pair('G', 0));
   	DNAs.push_back(make_pair('T', 0));
}

int main(void) {
	vector< pair<char, int> > DNAs;
	int n, m;
	vector<string> v;
   
   cin >> n >> m;
   string s, DNA;
   for(int i=0; i<n; ++i) {
      cin >> s;
      v.push_back(s);
   }
   for(int i=0; i<m; ++i) { // �� ������ �Ʒ��� Ž��. 
   		refresh(DNAs);
      for(int j=0; j<n; ++j) { // �̷��� �����ϸ� �ý��ۼ���Ʈ���������� ��ȿ���� ������.. 
         char value = v[j][i];
         if(value == 'A') ++DNAs[0].second;
         else if(value == 'C') ++DNAs[1].second;
         else if(value == 'G') ++DNAs[2].second;
         else ++DNAs[3].second;
      }
      sort(DNAs.begin(), DNAs.end(), compare);
      DNA.push_back(DNAs[0].first);
   }
   cout << DNA << endl;
   // Haming distance ���ϱ�. 
   int distance = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(DNA[j] != v[i][j])
				++distance;
		}
	}
	cout << distance;
   return 0;
}
