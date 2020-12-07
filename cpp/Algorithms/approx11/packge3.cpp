#include <iostream>
#include <algorithm>
using namespace std;

bool compr(int m, int n)
{
    return m > n;
}
int f[20000];

int main()
{
    int v;
    cin >> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    sort(f, f + n, compr);
    for (int i = 0; i < n; i++)
    {
        cout << f[i] << endl;
    }
    for (int t = 0; t < n; t++)
    {
        if (f[t] > v)
        {
        }
        else
        {
            v -= f[t];
        }
    }
    cout << v;
}