/**
 * string类
 * 构造
 * 追加
 * 复制
 * 位置与清除
 * 长度与容量
 * 比较
 * 子串
 * 搜索
 * 运算符
 */
#include<iostream>
using namespace std;

int main()
{
    string s = "Hello";


    char arr[]{'H', 'e', 'l', 'l', 'o'};

    s += arr;

    s.assign("Hello,World!");
    
    cout << s << endl;
    retun(0);
}
