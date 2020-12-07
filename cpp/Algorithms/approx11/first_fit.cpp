#include <iostream>
using namespace std;
void first_fit(float s[], int n, float C, float b[], int &k)
{
    int i, j;
    k = 0; //装入物体的箱子下标
    for (i = 0; i < n; i++)
    { //箱子初始化为空
        b[i] = 0;
    }
    for (i = 0; i < n; i++) //按物体顺序装入
    { //按物体顺序装入
        j = 0;
        while ((C - b[j] < s[i])) //检索能容纳物体i的下标最小的箱子j
        {
            j++;
        }
        b[j] += s[i];
        k = max(k, j); //已装入物体的箱子最大下标
    }
    k++; //箱子的最大下标转换为箱子的个数
}