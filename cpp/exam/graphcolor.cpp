// color[n] n个顶点的着色情况
// arc[n][n] 存储顶点边之间的情况

// 输入G，m种颜色
// n个顶点的涂色情况color[n]

// 1.将color[n]初始化为0
// 2.k=0
// while(k>=0)
// {
//     3.1依次考察每一种颜色，若顶点k的着色与其它顶点的着色不发生冲突，则转步骤3.2。否则，搜索下一个颜色
//     3.2若顶点已全部着色，则输出数组color[n]，返回
//     3.3若顶点k是一个合法着色，则k=k+1，转步骤3处理下一个节点
//     3.4否则，重置顶点k的着色情况，k=k-1，转步骤3回溯
// }
const int n = 10;
int arc[n][n];
int color[n];

#include <iostream>
using namespace std;

int OK(int k)
{
    for (int i = 0; i < k; i++)
    {
        if (arc[k][i] == 1 && color[i] == color[k])
        {
            return 0;
        }
        return 1;
    }
}

void graphcolor(int m)
{
    int i, k;
    for (i = 0; i < n; i++)
    {
        color[i] = 0;
    }
    k = 0;
    while (k >= 0)
    {
        color[k] = color[k] + 1;
        while (color[k] <= m)
        {
            if (OK(k))
            {
                break;
            }
            else
            {
                color[k] = color[k] + 1;
            }
            if (color[k] <= m && k == n - 1)
            {
                for (i = 0; i < n; i++)
                {
                    cout << color[i] << " ";
                }
                return;
            }
            if (color[k] <= m && k < n - 1)
            {
                k = k + 1;
            }
            else
            {
                color[k--] = 0;
            }
        }
    }
}

int main()
{
    return 0;
}
