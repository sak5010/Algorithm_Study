/*
    �־����� �Ž�����(m)�� ä�� �� �ִ� ���� ���� ȭ���� �� ����ϱ�.
    Greedy �˰������� Ǯ�� ������ �ظ� ���� �� �ִ�.
    ���� ū ������ �����ϸ� �ȴ�.
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
