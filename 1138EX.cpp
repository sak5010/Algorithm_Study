#include <iostream>

using namespace std;

int d[11];

int main(void) {
    int N;
    cin >> N;
    for(int i=1; i<=N; ++i) {
        int x, count = 0;
        cin >> x;
        for(int j=1; j<=N; ++j) { // �� ĭ�� �̵��ϸ� ����ִ� ���� ã�´�.
            if(x == count && d[j] == 0) { // ��������� �ڱ⺸�� ū ��� �� ��ŭ �̵��ߴٸ� �ִ´�.
                d[j] = i;
                break;
            }
            if(d[j] == 0) // ����ְ� ū ��ŭ �̵����� �ʾҴٸ� count�� ���ְ� �̵��� �Ѵ�.
                ++count;  // ������� �ʴٸ� �ϴ� ����ִ� ���� ã�ƾ� �ϹǷ� count++�� ���� �ʴ´�.
        }
    }
    for(int i=1; i<=N; ++i)
        cout << d[i] << " ";

    return 0;
}
