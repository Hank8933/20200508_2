#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
    int min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    return min;
}

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int maxSqure1(int n, int m, int m2, int (*a)[m2])
{
    if (n < 0 || m < 0) return 0;
    if (*(*(a + n) + m)) return 0;

    return min(maxSqure1(n-1, m, m2, a), maxSqure1(n, m-1, m2, a), maxSqure1(n-1, m-1, m2, a)) + 1;
}

int maxSqure(int n, int m, int m2, int (*a)[m2], int flag)
{
    if (n < 0 || m < 0) return 0;

    int ans = max(max(maxSqure(n-1, m, m2, a, 0), maxSqure(n, m-1, m2, a, 0)), maxSqure1(n, m, m2, a));

    return (flag) ? ans * ans : ans;
}

int main()
{
    //freopen("map", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    int b[n][m];

    for (int i =0; i < n; i++)
        for (int j = 0; j < m; j++){
            scanf("%d", (*(a+i)+j));
            *(*(b + i) + j) = 0;
        }

    printf("%d\n", maxSqure(n-1, m-1, m, a, 1));
    return 0;
}
