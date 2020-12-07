int KnapSack(int w[], int v[], int n, int C)
{
    double x[10] = {0};
    int maxValue = 0;
    int i;
    for (i = 0; w[i] < C; i++)
    {
        x[i] = 1;
        maxValue += v[i];
        C = C - w[i];
    }
    x[i] = (double)C / w[i];
    maxValue += x[i] * v[i];
    return maxValue;
}