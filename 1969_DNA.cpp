/*
   각 열마다 아래로 탐색하면서 A, T, G, C 중에 가장 많은 것을 선택한다.
   4가지 물질의 수가 모두 같다면 사전 순서대로 앞선 물질을 선택한다.
   이렇게 해서 나온 DNA가 Hamming Distance의 합이 가장 작은 DNA다.
   Hamming Distance를 구하는 방법은 찾은 DNA와 입력받은 DNA들을
   물질 하나 하나 비교해 가면서 서로 다른 물질을 만났을때마다
   Hamming Distance의 값을 ++ 해주면 된다.
   탐색이 모두 끝나면 Hamming Distance의 값을 찾을 수 있다. 
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using namespace std;

bool compare(const pair<char, int>& a, const pair<char, int>& b) {
   if(a.second == b.second) { // 등장 빈도수가 같으면 사전순 정렬. 
      return a.first < b.first;
   }
   else { // 다르면 빈도수 내림차순 정렬. 
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
   for(int i=0; i<m; ++i) { // 각 열마다 아래로 탐색. 
   		refresh(DNAs);
      for(int j=0; j<n; ++j) { // 이렇게 접근하면 시스템소프트웨어적으로 비효율적 이지만.. 
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
   // Haming distance 구하기. 
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
