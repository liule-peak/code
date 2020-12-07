#include <iostream>
using namespace std;

int TSP1(int arc[n][n], int w)
{
    int edgeCount=0;
    int TSPLength=0;
    int flag[n]={0};
    u=w;flag[w]=1;
    while(edgeCount<n-1)
    {
        min=100;
        for(j=0;j<n;j++)
        {
            if((flag[j]==0)&&(arc[u][j]!=0)&&(arc[u][j]<min))
            {
                v=j;
                min=arc[u][j];
            }
        }
        TSPLength+=arc[u][v];
        flag[v]=1;edgeCount++;
        cout <<u <<"-->"<<w<<endl;
        return (TSPLength+arc[u][w])
    }
}