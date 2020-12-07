#include <iostream>
#include <cstring>
using namespace std;

void GetNext(char T[], char next[])
{
    int k = -1;
    int j = 0;
    next[0] = -1;
    while (T[j] != '\0')
    {
        if (k == -1)
        {
            next[++j] = 0;
            k = 0;
        }
        else if (T[j] == T[k])
        {
            k++;
            next[++j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int KMP(char S[], char T[])
{

    char next[80];
    GetNext(T, next);
    int i = 0, j = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
            if (j == -1)
            {
                ++i;
                ++j;
            }
        }
    }
    if (T[j] == '\0')
    {
        return (i - strlen(T) + 1);
    }
    else
    {
        return -1;
    }
}
int main()
{
    char S[] = "abcabdca";
    char T[] = "abd";
    cout << KMP(S, T);
    return 0;
}