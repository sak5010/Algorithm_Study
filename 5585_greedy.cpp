#include <stdio.h>

int main(void) {
    int m, result = 0;
    scanf("%d", &m);
    m = 1000 - m;

    result += m/500;
    m %= 500;

    result += m/100;
    m %= 100;

    result += m/50;
    m %= 50;

    result += m/10;
    m %= 10;

    result += m/5;
    m %= 5;

    result += m/1;
    m %= 1;

    printf("%d", result);

    return 0;
}
