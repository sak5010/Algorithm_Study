/*
    i) �������� �����Ѵ�. 1 2 3 3 4
    ii) 1 + 3 + 6 + 9 + 13 ó�� �տ��� ���� �����ϸ� ���Ѵ�.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int P[1001];

int main(void) {
    int N, accum = 0, sum = 0;
    cin >> N;
    for(int i=0; i<N; ++i)
        cin >> P[i];

    sort(P, P+N);

    for(int i=0; i<N; ++i) {
        accum += P[i];
        sum += accum;
    }
    printf("%d", sum);

    return 0;
}
