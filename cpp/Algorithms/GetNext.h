void GetNext(char T[], int next[])
{
    int i, j, len;
    next[0] = -1;
    for (j = 1; T[j] != '\0'; j++)
    {
        for (len = j - 1; len >= 1; len--)
        {
            for (i = 0; i < len; i++)
            {
                if (T[i] != T[j - len + 1])
                {
                    break;
                }
            }
            if (i == len)
            {
                next[j] = len;
                break;
            }
        }
        if (len < 1)
        {
            next[j] = 0;
        }
    }
}