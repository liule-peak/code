#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN (5000+10)

struct Point{
    int x, y;
};

int r, c;
int n;
int ans = 0;
bool flag[MAXN][MAXN];
Point p[MAXN];

bool operator < (const Point &a,const Point &b){
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

bool Outside(int x1,int y1){
    if(x1 <= 0||y1 <= 0||x1 > r||y1 > c) return true;
    return false;
}

bool count(int a,int b){   
    int dx = p[b].x - p[a].x;
    int dy = p[b].y - p[a].y;

    if(!Outside(p[a].x-dx,p[a].y-dy)){
        return false;
    }
    if(p[a].x+ans*dx<=0||p[a].x+ans*dx>r){
        return false;
    }
    if(p[a].y+ans*dy<=0||p[a].y+ans*dy>c){
        return false;
    }
    int k = 2;
    int x1 = p[b].x + dx;
    int y1 = p[b].y + dy;
    while(!Outside(x1,y1)&&flag[x1][y1]){
        ++k;
        x1 += dx;
        y1 += dy;
    }

    if(Outside(x1,y1)&&k>ans){
        ans = k;
    }
}

int main(){
    scanf("%d%d%d", &r, &c, &n);
    for (int i = 0; i < n;++i){
        scanf("%d%d", &p[i].x, &p[i].y);
        flag[p[i].x][p[i].y] = true;
    }
    sort(p, p + n);
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n; ++j){
            count(i, j);
        }
    }
    if(ans<3){
        ans = 0;
    }
    printf("%d\n", ans);
    return 0;
}