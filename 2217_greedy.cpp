/*
100 200 300
i) 오름차순 정렬
ii) 작은 값 부터 시작 해서 (값 * 남은 로프의 수)로 곱해서 합을 저장.
    즉, 맨 마지막 값은 남은 로프의 수가 자기 하나이므로 그 값 하나임.
    이렇게 max값을 갱신해 나감.
iii) 마지막에 남은 max값이 그 로프로 들 수 있는 최대값이다.
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
