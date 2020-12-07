void GetNext(char T[], int next[])
{
    int j = 0;
    int k = -1;
    next[0] = -1;
    while (T[j] != '\0')
    {
        if (k == -1)
        {
            next[++j] = 0;
            k = 0;
        }
        else if (T[k] == T[j])
        {
            ++k;
            next[++j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}