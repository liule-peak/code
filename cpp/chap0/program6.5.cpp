/**
 * 田忌赛马问题
 * @author liule
 * （1）最快马。若田忌快，则使用田忌最快马对齐王最快马
 * （2）最快马。若齐王快，则使用田忌最慢马对齐王最快马
 * （3）最快马。两者同速：
 *  ①：最慢马田忌快，则使用田忌最慢马对齐王最慢马。
 *  ②：否则，则使用田忌最慢马对齐王最快马。
 *  以上每一步选择均是最优，因此结果最优。                     
 */

#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN(1000);     //最多1000只马
int n, money, l1, l2, r1, r2;

/**n:the number of horses;
 * l1:the lowest of tianji's horse
 * l2:the lowest of Qi's horse
 * r1:the best of tianji's horse
 * r2:the best of Qi's horse
 */

int a[MAXN], b[MAXN];

int main()
{
    cin >> n;
    while(n!=0)
    {
        for (int i = 0; i < n;++i)
        {
            cin >> a[i];    // horses of tianji
        }
        for (int i = 0; i < n;++i)
        {
            cin >> b[i];    // horses of kingQi
        }

        sort(a, a + n);     //sort
        sort(b, b + n);     //sort

        money = 0;
        l1 = l2 = 0;
        r1 = r2 = n - 1;

        while(l1 <= r1)
        {
            if(a[r1]>b[r2])   //最快马。若田忌快，则使用田忌最快马对齐王最快马
            {
                money += 200;
                --r1;
                --r2;
            }else if(a[r1] < b[r2])   //最快马。若齐王快，则使用田忌最慢马对齐王最快马
            {
                money -= 200;
                ++l1;
                --r2;
            }
            else    //最快马。两者同速：
            {
                if(a[l1]>b[l2])  //最慢马田忌快，则使用田忌最慢马对齐王最慢马。
                {
                    money += 200;
                    ++l1;
                    ++l2;
                }
                else
                {
                    if(a[l1] < b[r2])    //否则，则使用田忌最慢马对齐王最快马。
                    {
                        money -= 200;
                    }
                    ++l1;
                    --r2;
                }  
            }
        }
        cout << money << endl;
        cin >> n;
    }
    return (0);
}