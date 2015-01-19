#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <cstring>
#include <cctype>
#include <set>
using namespace std;
int V, e, a, b, ori, ok, gra[300+5];
bool adj[300+5][300+5],  vis[300+5];
queue<int> que;

void bfs(int);
int main()
{
    while(~scanf("%d", &V) && V){
        memset(adj, false, sizeof(adj));
        memset(vis, false, sizeof(vis));
        memset(gra, 0, sizeof(gra));
        while(scanf("%d %d", &a, &b)){
            if(a==0 && b==0) break;
            adj[a][b] = true, adj[b][a] = true;
        }
        ok=1;
        for(int i=0 ; i<V ; i++){
            if(!vis[i]) bfs(i);
            if(!ok) break;
        }
        if(ok)
            puts("YES");
        else
            puts("NO");
        while(!que.empty()) que.pop();
    }
    return 0;
}

void bfs(int head)
{
    que.push(head);
    gra[head] = 1;
    while(!que.empty()){
        ori = que.front();
        que.pop();
        vis[ori] = true;
        for(int i=0, ct=0 ; i<V && ct<3 ; i++){
            if(adj[ori][i]){
                if(vis[i]){
                    if(gra[ori]==gra[i])
                        ok=0;
                }
                else{
                    gra[i] = !gra[ori];
                    vis[i] = true;
                    que.push(i);
                    ct++;
                }
            }
            if(!ok)
                break;
        }
        if(!ok)
            break;
    }
    while(!que.empty()) que.pop();
}
