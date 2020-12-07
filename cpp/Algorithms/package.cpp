#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int f[20001];
int main()
{
   int n,m,i,j,k,v,t;
   cin>>v>>n;
   for(i=1;i<=n;i++)
   {
     cin>>k;
     for(j=v;j>=1;j--)
       if(j>=k)
         f[j]=max(f[j],f[j-k]+k);
     }
   k=v-f[v];
   cout<<k<<endl;
   return 0;
}