#include <stdio.h>

int coinValue[10];

int main(void) {
    int N, K, cntOfCoin = 0;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; ++i)
        scanf("%d", &coinValue[i]);

    for(int i=N-1; i>=0; --i) {
        cntOfCoin += K/coinValue[i];
        K %= coinValue[i];
    }
    printf("%d", cntOfCoin);

    return 0;
}
