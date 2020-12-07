#include <iostream>
using namespace std;

void Best_fit(float s[], int n, float C, float b[], int &k)
{
    int i, j;
    k = 0; //初始化
    for (j = 0; j < n; j++)
    {
        b[j] = 0;
    }
    for (i = 0; i < n; i++) //装入第i个物品
    {
        min = C;
        m = k + 1;
        for (j = 1; j <= k; j++) //查找容纳物品i并且目前最满的编号最小的箱子
        {
            temp = C - b[j] - s[i];
            if (temp > 0 && temp < min {min=temp;m=j; })
        }
        b[m] += s[i];
        k = max(k, m); //已装入物体的箱子最大下标
    }
    return k; //已装入物品的箱子个数
}