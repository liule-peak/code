#include <iostream>

using namespace std;

int arr[31][20001] = {0};
int co[31];
int main()
{
    int v, n;
    cin >> v >> n;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        cin >> co[i];
    }
    for (i = 1; i <= v; i++)
    {
        arr[0][i] = i;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= v; j++)
        {
            if (j >= co[i])
            {
                arr[i][j] = min(arr[i - 1][j], arr[i - 1][j - co[i]]);
            }
            else
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
        for (int k = 1; k <= v; k++)
        {
            cout << arr[i][k] << " ";
        }
        cout << endl;
    }
    cout << arr[n][v];
}

/*
24
6
8
3
12
7
9
7
*/