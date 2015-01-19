#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;
int N, M, dis[750+5], parent[750+5];
int X[750+5], Y[750+5], all[750+5][750+5];
bool vis[750+5];
struct edge{
    int pre, next;
};
edge t;
vector<edge> ans;
int main()
{
    int test, x=0, y=0, px=-1, py=-1, times=0;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        memset(vis, false, sizeof(vis)), memset(all, 0, sizeof(all));
        ans.clear();
        for(int i=0 ; i<=754 ; i++)
            X[i] = 0, Y[i] = 0, dis[i] = 1e9, parent[i] = -1;
        for(int i=0 ; i<N ; i++)
            scanf("%d %d", &X[i+1], &Y[i+1]);
        for(int i=1 ; i<=N ; i++)
            for(int j=1 ; j<=N ; j++)
                all[i][j] = (X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
        scanf("%d", &M);
        for(int i=0 ; i<M ; i++)
            scanf("%d %d", &x, &y), all[x][y] = 0, all[y][x] = 0;
        dis[1] = 0, parent[1]=0;
        for(int i=1 ; i<=N ; i++){
            int a=-1, b=-1, mini = 1e9;
            for(int j=1 ; j<=N ; j++)
                if(!vis[j] && dis[j]<mini)
                    a = j, mini = dis[j];
            if(a==-1) break;
            vis[a] = 1;
            if(mini>0)
                t.pre = a, t.next = parent[a], ans.push_back(t);
            for(b=1 ; b<=N ; b++)
                if(!vis[b] && dis[b]>all[a][b])
                    dis[b] = all[a][b], parent[b] = a;
        }
        if(ans.size()>0)
            for(int i=0 ; i<(int) ans.size() ; i++)
                printf("%d %d\n", ans[i].pre, ans[i].next);
        else
            puts("No new highways need");
        if(test>0) putchar(10);
    }
    return 0;
}
