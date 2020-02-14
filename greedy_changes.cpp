/*
    주어지는 거스름돈(m)을 채울 수 있는 가장 적은 화폐의 수 계산하기.
    Greedy 알고리즘으로 풀면 최적의 해를 구할 수 있다.
    가장 큰 값부터 생각하면 된다.
*/

#include <stdio.h>

int main(void) {
    int m, result = 0;
    scanf("%d", &m);

    result += m/500;
    m %= 500;

    result += m/100;
    m %= 100;

    result += m/50;
    m %= 50;

    result += m/10;
    m %= 10;

    printf("%d\n", result);

    return 0;
}
