#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int graph[6][4]={{}, {2,3,5,-1}, {1,3,5,-1}, {1,2,4,5}, {3,5,-1,-1}, {1,2,3,4}};
int ans[9];
bool visit[6][6];
void findans(int, int);

int main()
{
    memset(visit, false, sizeof(visit));
    for(int i=0 ; i<6 ; i++)
        visit[0][i] = true, visit[i][0] = true;
    ans[0] = 1;
    findans(1,1);
    return 0;
}

void findans(int cur, int layer)
{
    if(layer==9){
        for(int i=0 ; i<9 ; i++)
            putchar(ans[i]+'0');
        putchar(10);
        return;
    }
    for(int i=0 ; i<4 && graph[cur][i]!=-1 ; i++){
        if(!visit[cur][graph[cur][i]] && !visit[graph[cur][i]][cur]){
            visit[cur][graph[cur][i]] = true, visit[graph[cur][i]][cur] = true;
            ans[layer] = graph[cur][i];
            findans(graph[cur][i], layer+1);
            visit[cur][graph[cur][i]] = false, visit[graph[cur][i]][cur] = false;
        }
    }
}
