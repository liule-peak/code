/**
 * (1) 输入 容量：v， 物品数量：n, 每一个物品的体积vi。
 * (2) 输出 最小的剩余空间
 * (3) 将vi存储在 co[i] 数组中。
 * (4) 初始化 f[0][i]，f[i][j]代表最小的剩余空间。
 * (5) for 循环 考虑 第i个物体
 *       for 循环 f[i][j] = min(f[i-1][j],f[i-1][j-co[i]])
 * 
 */
#include <iostream>
using namespace std;
int f[20001];

int main()
{
    int v, n;
    cin >> v >> n;
    int co[30];
    int i, j;
    for (i = 1; i <= n; i++)
    {
        cin >> co[i];
    }
    for (i = 1; i <= v; i++)
    {
        f[i] = i;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= v; j++)
        {
            if (j >= co[i])
            {
                f[j] = min(f[j], f[j - co[i]]);
            }
            else
            {
                f[j] = f[j];
            }
        }
        for (int k = 1; k <= v; k++)
        {
            cout << f[k] << " ";
        }
        cout << endl;
    }
    cout << f[v];
    return 0;
}