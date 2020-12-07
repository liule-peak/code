#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
//记忆递归类型，使用一个二维数组将i，j下面的最大值记住。

int D[MAX][MAX];
int maxSum[MAX][MAX];
int n;

int MaxSum(int i, int j)
{
    if (maxSum[i][j] != -1)
    {
        return maxSum[i][j];
    }
    if (i == n)
    {
        maxSum[i][j] = D[i][j];
    }
    else
    {
        int x = MaxSum(i + 1, j);   //递归
        int y = MaxSum(i + 1, j + 1);   //递归
        maxSum[i][j] = max(x, y) + D[i][j];
    }
    return maxSum[i][j];
}

int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cin >> D[i][j];
            maxSum[i][j] = -1;
        }
        
    }
    cout << MaxSum(1, 1) << endl;
}