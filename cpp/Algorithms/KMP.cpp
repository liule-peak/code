#include <iostream>
#include <cstring>
using namespace std;

void GetNext1(char T[], int next[]) 
{
    int i, j, len;
    next[0] = -1;                  //next[0] 设置为 -1
    for (j = 1; T[j] != '\0'; j++) //依次 next[j]
    {
        for (len = j - 1; len >= 1; len--) //先假定最长公共前后缀len为j-1，不满足条件则将len--
        {
            for (i = 0; i < len; i++) //依次比较T[i] 与 T[j - len + 1] 若相等则继续向后比较，不等就跳出。
            {
                if (T[i] != T[j - len + 1])
                {
                    break;
                }
            }
            if (i == len) //如果i与len相等，则表明next[j]=len
            {
                next[j] = len;
                break;
            }
        }
        if (len < 1) //len<1，则表明next[j]=0；
        {
            next[j] = 0;
        }
    }
}

void GetNext(char T[], int next[])
{
    int j = 0, k = -1;
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
    int i = 0, j = 0;
    int next[80];
    GetNext(T, next);
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j]; //字符不等时，T串回退到next[j]位置。
            if (j == -1)
            {
                i++;
                j++;
            }
        }
    }

    if (T[j] == '\0')
    {
        return (i - strlen(T) + 1); //返回T在S中的第几个位置（非下标）
    }

    else
    {
        return -1;
    }
}

int main()
{
    char S[] = "ababcabccabcabcbab";
    char T[] = "abcab";
    cout << KMP(S, T) << endl;
}