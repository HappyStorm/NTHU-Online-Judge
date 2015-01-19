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
using namespace std;
int S, N, M, tx, ty, water[100+5][100+5], dir[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
bool visit[100+5][100+5];
struct node{
    int x, y, time;
};
node ori, tn;
queue<node> nodeque;

void flow();
int main()
{
    int times=1;
    while(~scanf("%d", &S)){
        scanf("%d %d", &N, &M);
        memset(water, -1, sizeof(water));
        memset(visit, false, sizeof(visit));
        for(int i=1 ; i<=N ; i++)
            for(int j=1 ; j<=M ; j++)
                scanf("%d", &water[i][j]);
        for(int i=1 ; i<=M ; i++)
            if(water[1][i]==1){
                tn.x=1, tn.y=i, tn.time=1;
                visit[tn.x][tn.y] = true;
                nodeque.push(tn);
                break;
            }
        flow();
        printf("Case %d:\n", times++);
        for(int i=1 ; i<=N ; i++){
            for(int j=1 ; j<=M ; j++){
                if(i==1){
                    if(j!=M)
                        printf("%d ", water[i][j]);
                    else
                        printf("%d", water[i][j]);
                }
                else{
                    if(j!=M){
                        if(water[i][j]==1)
                            printf("0 ");
                        else
                            printf("%d ", water[i][j]);
                    }
                    else{
                        if(water[i][j]==1)
                            printf("0");
                        else
                            printf("%d", water[i][j]);
                    }
                }
            }
            putchar(10);
        }
    }
    return 0;
}

void flow()
{
    if(S==1){
        while(!nodeque.empty()){
            ori = nodeque.front();
            nodeque.pop();
            if(ori.x<0 || ori.y<0 || ori.x>N || ori.y>M)
                return;
            for(int i=0 ; i<4 ; i++){
                tn.x = ori.x+dir[i][0], tn.y = ori.y+dir[i][1], tn.time = ori.time+1;
                if(water[tn.x][tn.y]!=1 || visit[tn.x][tn.y]) continue;
                visit[tn.x][tn.y] = 1;
                water[tn.x][tn.y] = tn.time;
                nodeque.push(tn);
            }
        }
    }
    else if(S==2){
        while(!nodeque.empty()){
            ori = nodeque.front();
            nodeque.pop();
            if(ori.x<0 || ori.y<0 || ori.x>N || ori.y>M)
                return;
            for(int i=0 ; i<3 ; i++){
                tn.x = ori.x+dir[i][0], tn.y = ori.y+dir[i][1], tn.time = ori.time+1;
                if(water[tn.x][tn.y]!=1  || visit[tn.x][tn.y]) continue;
                visit[tn.x][tn.y] = 1;
                water[tn.x][tn.y] = tn.time;
                nodeque.push(tn);
            }
        }
    }
}
