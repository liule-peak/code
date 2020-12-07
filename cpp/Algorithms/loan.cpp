/**设贷了a元，每月还款b，还款周期为m个月，月利率在x=0 和 y=100之间。
 * 进入for循环
 * a=a(1+x)-b;
 * if a > 0 说明利率太高，则将利率上限调低;
 * if a < 0 说明利率太低，则将利率上限调高;
 * 上下限近似相等时，说明利率恰好是此值
 * stop;
 */
#include <iostream>

int main()
{
    double a, b, m, x = 0, y = 100;
    std::cout << "please input the loan number and repay number" << std::endl;
    std::cin >> a >> b;

    while (a < 1 || a > 10e9)
    {
        std::cout << "the loan number or repay number error" << std::endl;
        std::cout << "please input the loan number and repay number again" << std::endl;
        std::cin >> a >> b;
    }

    while (b < 1 || b > 10e9)
    {
        std::cout << "the loan number or repay number error" << std::endl;
        std::cout << "please input the loan number and repay number again" << std::endl;
        std::cin >> a >> b;
    }

    std::cout << "please input the months number" << std::endl;
    std::cin >> m;
    while (m < 1 || m > 10e4)
    {
        std::cout << "the months number error" << std::endl;
        std::cout << "please input the months number again" << std::endl;
        std::cin >> m;
    }
    while (y - x > 1e-5)
    {
        double n = x + (y - x) / 2; //划分
        double f = a;
        for (int i = 0; i < m; i++)
            f = f + f * n / 100.0 - b;
        if (f < 0)
            x = n;
        else
            y = n;
    }
    std::cout << x << "%";
}