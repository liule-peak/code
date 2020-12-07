#include <iostream>
using namespace std;

const int MAX = 1000;
const int N = 10;
int arc[N][N];

int createGraph()
{
    int i, j, k;
    int weight;
    int vnum, arcnum;
    cout << "please input the number of vnum and arcnum." << endl;
    cin >> vnum >> arcnum;
    for (i = 0; i < vnum; i++)
    {
        for (j = 0; j < vnum; j++)
        {
            arc[i][j] = MAX;
        }
    }
    for (k = 0; k < arcnum; k++)
    {
        cout << "please input the weight of two vect: ";
        cin >> i >> j >> weight;
        arc[i][j] = weight;
    }
    return vnum;
}

int getMinPath(int n)
{
    int i, j, temp;
    int cost[N], path[N];
    for (i = 0; i < n; i++)
    {
        cost[i] = MAX;
        path[i] = -1;
    }
    cost[0] = 0;
    path[0] = 0;
    for (j = 1; j < n; j++)
    {
        for (i = j - 1; i >= 0; i--)
        {
            if (cost[i] + arc[i][j] < cost[j])
            {
                cost[j] = cost[i] + arc[i][j];
                path[j] = i;
            }
        }
    }
    cout << n - 1;
    i = n - 1;
    while (path[i] >= 0)
    {
        cout << "->" << path[i];
        i = path[i];
    }

    cout << endl;
    return cost[n - 1];
}

int main()
{
    int n = createGraph();
    cout << getMinPath(n) << endl;
    return 0;
}

/*
 0 1 4
 0 2 2
 0 3 3
 1 4 9
 1 5 8
 2 4 6
 2 5 7
 2 6 8
 3 5 4
 3 6 7
 4 7 5
 4 8 6
 5 7 8
 5 8 6
 6 7 6
 6 8 5
 7 9 7
 8 9 3
 */