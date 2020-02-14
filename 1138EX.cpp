#include <iostream>

using namespace std;

int d[11];

int main(void) {
    int N;
    cin >> N;
    for(int i=1; i<=N; ++i) {
        int x, count = 0;
        cin >> x;
        for(int j=1; j<=N; ++j) { // 한 칸씩 이동하며 비어있는 곳을 찾는다.
            if(x == count && d[j] == 0) { // 비어있으며 자기보다 큰 사람 수 만큼 이동했다면 넣는다.
                d[j] = i;
                break;
            }
            if(d[j] == 0) // 비어있고 큰 만큼 이동하지 않았다면 count도 해주고 이동도 한다.
                ++count;  // 비어있지 않다면 일단 비어있는 곳을 찾아야 하므로 count++를 하지 않는다.
        }
    }
    for(int i=1; i<=N; ++i)
        cout << d[i] << " ";

    return 0;
}
