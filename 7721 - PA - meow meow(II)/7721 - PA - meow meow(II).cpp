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
int N, ans, gra[100+5][100+5], visit[100+5][100+5], dir[4][2]={{-1,0}, {0,1}, {1,0}, {0,-1}};
char chgra[100+5][100+5];
struct p{
    int x, y, time;
};
p tp, ori;
queue<p> que;

void bfs();
int main()
{
    while(~scanf("%d", &N)){
        if(!N) break;
        getchar();
        memset(chgra, '\0', sizeof(chgra));
        memset(gra, 0, sizeof(gra));
        memset(visit, 0, sizeof(visit));
        for(int i=0 ; i<N ; i++)
            gets(chgra[i]);
        int len = strlen(chgra[0]);
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<len ; j++){
                if(chgra[i][j]=='#') gra[i][j] = 0;
                else if(chgra[i][j]=='.') gra[i][j] = 1;
                else if(chgra[i][j]=='K') gra[i][j] = 1, tp.time = 0, tp.x = i, tp.y = j, que.push(tp);
                else if(chgra[i][j]=='@') gra[i][j] = 1;
            }
        }
        ans=0;
        bfs();
        if(ans)
            printf("%d\n", ans);
        else
            printf("= =\"\n");
    }
    return 0;
}

void bfs()
{
    while(!que.empty()){
        ori = que.front();
        if(chgra[ori.x][ori.y]=='@'){
            ans = ori.time;
            while(!que.empty()) que.pop();
            return;
        }
        que.pop();
        for(int i=0 ; i<4 ; i++){
            tp.x = ori.x + dir[i][0], tp.y = ori.y + dir[i][1], tp.time = ori.time+1;
            if(!gra[tp.x][tp.y] || visit[tp.x][tp.y]) continue;
            visit[tp.x][tp.y] = 1;
            que.push(tp);
        }
    }
}
