#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char a[25][80];
int main(void)
{
    int b, c, r;
    int y, x;
    double th, dth;
    char C[128];

    printf("******\n");

    printf("�c�F");
    scanf("%s", C);
    b = atoi(C);

    printf("���F");
    scanf("%s", C);
    c = atoi(C);

    printf("���a�F");
    scanf("%s", C);
    r = atoi(C);

    if (r > 0)
        dth = 2.0 / r;
    else
        dth = 6.28;
    for (y = 0; y < 25; y++)
        memset(&a[y][0], ' ', c * 2 + r * 2);
    for (th = 0.0; th < 6.28; th += dth)
    {
        x = (int)(r * 2 * cos(th) + c * 2);
        y = (int)(r * sin(th) + b);
        if (x < 0 || x > 79)
            continue;
        if (y < 0 || y > 23)
            continue;
        a[y][x] = '*';
    }
    for (y = 23; y >= 0; y--)
    {
        printf("%s\n", &a[y][0]);
    }
    fflush(stdout);
    rewind(stdin);
    getchar();
    return 0;
}