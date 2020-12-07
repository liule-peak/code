P[] = data_jd(); //数组P代表要处理的数据

ave = mean(P); //mean 求解平均值

u = std(P);
求出P的标准差，赋值给u

    int k = 0;                          //用于统计异常值的数量
int Plength = sizeof(P) / sizeof(p[0]); //使用PLength  存放数组P的长度
for (int i = 0; i < Plength; i++)
{
    if (abs(P[i] - ave) > 3 * u) //此处的P是数据数组
        P[i] = 0;
    k++;
    cout << i << " "; //将异常值下标i输出
}
for (int i = 0; i < Plength; i++)
{
    if (p[i] == 0)
    { //如果某个值为0，则将此值之后的值前移一位。
        for (int j = i + 1; j < Plength; j++)
        {
            p[j] = p[j + 1];
        }
    }
}

for (int i = 0; i < Plength - k；i++)
{
    cout << P[i] << endl; //将下标0到Plength-k-1的数组（正常值）输出
}
