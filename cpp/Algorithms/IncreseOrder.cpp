#include <iostream>
using namespace std;

int IncreaseOrder(int a[], int n)
{
    int i, j, k, index;
    int L[10];
    int x[10][10];

    for (i = 0; i < n; i++)
    {
        L[i] = 1;
        x[i][0] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        int max = 1;
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] < a[i] && (max < L[j] + 1))
            {
                max = L[j] + 1;
                L[i] = max;
                for (k = 0; k < max - 1; k++)
                {
                    x[i][k] = x[j][k];
                }
                x[i][max - 1] = a[i];
            }
        }
    }
    for (index = 0, i = 1; i < n; i++)
    {
        if (L[index] < L[i])
        {
            index = i;
        }
    }
    cout << "the longest of IncreaseOder is: ";
    for (i = 0; i < L[index]; i++)
    {
        cout << x[index][i] << " ";
    }
    cout << endl;
    return L[index];
}

int main()
{
    int a[8] = {5, 2, 8, 6, 3, 6, 9, 7};
    cout << IncreaseOrder(a, 8) << endl;
}