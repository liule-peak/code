#include <iostream>
using namespace std;

const int N = 100;

int CommenSubSeq(char A[], int m, char B[], int n)
{
    int L[N][N];
    int S[N][N];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        L[i][0] = 0;
    }
    for (j = 0; j <= n; j++)
    {
        L[0][j] = 0;
    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (A[i] == B[j])
            {
                L[i][j] = L[i - 1][j - 1] + 1, S[i][j] = 1;
            }
            else if (L[i][j - 1] >= L[i - 1][j])
            {
                L[i][j] = L[i][j - 1];
                S[i][j] = 2;
            }
            else
            {
                L[i][j] = L[i - 1][j];
                S[i][j] = 3;
            }
        }
    }
    for (; i > 0 && j > 0;)
    {
        if (S[i][j] == 1)
        {
            i--;
            j--;
        }
        else if (S[i][j] == 2)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    return L[m][n];
}

int main()
{
    char x[] = {'a', 'b', 'c', 'b', 'd', 'b'};
    char y[] = {'a', 'c', 'b', 'b', 'a', 'b', 'd', 'b', 'b'};
    cout << CommenSubSeq(x, 6, y, 9);
    return 0;
}