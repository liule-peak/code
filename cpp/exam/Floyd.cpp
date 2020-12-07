const int n = 10;
void Floyd(int arc[n][n], int dist[n][n])
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; i < n; j++)
        {
            dist[i][j] = arc[i][j];
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}