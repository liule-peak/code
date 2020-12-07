#include<iostream>
using namespace std;

void greedy(int d[],int n,int k)
{
    int num,i,s;
    for(i=0;i<=k;i++)
    {
        if(d[i]>n)
        {
            cout << "no solution" << endl;
            return ;
        }
    }
    for(i=0,s=0;i<=k;i++)
    {
        s += d[i]; //记录当前最近几个点的总距离，一直到不能一次跑到为止。
        if(s>n) //不能到达时，在最近几个点，最远的那个站加油。
        {
            num++;
            s=d[i];
        }
    }
    cout << num << endl;
}
       
       
int main() {   
    int i,n,k;   
    int d[1000];   
    cin >> n >> k;  
    for(i = 0;i <= k;i++)   
        cin >> d[i];   
    greedy(d,n,k);   
}