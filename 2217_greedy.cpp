/*
100 200 300
i) �������� ����
ii) ���� �� ���� ���� �ؼ� (�� * ���� ������ ��)�� ���ؼ� ���� ����.
    ��, �� ������ ���� ���� ������ ���� �ڱ� �ϳ��̹Ƿ� �� �� �ϳ���.
    �̷��� max���� ������ ����.
iii) �������� ���� max���� �� ������ �� �� �ִ� �ִ밪�̴�.
*/

#include <stdio.h>
#include <algorithm>

int lope[100001];

int main(void) {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%d", &lope[i]);

    std::sort(lope, lope+N);

    int sum = 0, temp;
    for(int i=0; i<N; ++i) {
        temp = lope[i] * (N-i);
        if(temp > sum)
            sum = temp;
    }
    printf("%d", sum);

    return 0;
}
