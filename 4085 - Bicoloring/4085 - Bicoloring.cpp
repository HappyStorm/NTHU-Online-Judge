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
int node, edge, check;
bool connect[200+5][200+5];
int graph[200+5];
void bicolor(int);
int main()
{
    while(~scanf("%d", &node) && node){
        scanf("%d", &edge);
        memset(graph, -1, sizeof(graph));
        memset(connect, false, sizeof(connect));
        int a, b;
        for(int i=0 ; i<edge ; i++)
            scanf("%d %d", &a, &b), connect[a][b] = true, connect[b][a] = true;
        check=1, graph[0] = 0;
        bicolor(0);
        if(check)
            puts("BICOLORABLE.");
        else
            puts("NOT BICOLORABLE.");
    }
    return 0;
}

void bicolor(int now)
{
    if(!check)
        return;
    for(int i=0 ; i<node ; i++){
        if(connect[now][i])
            if(graph[i]==-1)
                graph[i] = !graph[now], bicolor(i), graph[i] = -1;
            else if(graph[i] != !graph[now]){
                check=0; return;}
    }
}
