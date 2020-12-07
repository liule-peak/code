#include <iostream>
using namespace std;

/**
 * 背包容量C，物体n个，每一个体积vi，价值wi
 */

int F[100] = {0};
int maxValue(int c, int n, int w[], int v[])
{
    int flag[n+1] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = c; j >= w[i - 1]; j--)
        {
            F[j] = max(F[j], F[j - w[i - 1]] + v[i - 1]);
            flag[i] =F[j]>F[j - w[i - 1]] + v[i - 1]?0:1;
        }
    }
    for(int k=1;k<=n;k++)
    {
        cout << flag[k] << " ";
    }
    return F[c];
}

int main()
{
    int c = 10;
    int n = 5;
    int w[] = {2, 2, 6, 5, 4};
    int v[] = {6, 3, 5, 4, 6};
    cout << maxValue(c, n, w, v);
    return 0;
}