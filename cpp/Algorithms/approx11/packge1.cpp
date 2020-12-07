#include <stdio.h>
#define MIN(a, b) ((a) > (b) ? (b) : (a))
int arr[2001] = {0};
int co[40];
int main()
{ //经典dp，01背包
    int v;
    int n;
    scanf("%d %d", &v, &n);
    int i;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", co + i);
    }
    int j;

    for (i = 1; i <= v; i++)
    {
        arr[i] = i;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = v; j >= co[i]; j--)
        {

            arr[j] = MIN(arr[j], arr[j - co[i]]);
        }
    }
    printf("%d", arr[v]);
}

/*
24

6

8

3

12

7

9

7
*/