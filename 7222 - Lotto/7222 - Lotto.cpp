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
int k, lucky[13], ans[6];
bool visit[50][50];

void lottery(int, int);
int main()
{
    int times=0;
    while(~scanf("%d", &k) && k){
        if(times++)
            putchar(10);
        memset(visit, false, sizeof(visit));
        for(int i=0 ; i<k ; i++)
            scanf("%d", &lucky[i]);
        lottery(0, 0);
    }
    return 0;
}

void lottery(int cur, int layer)
{
    if(layer==6){
        for(int i=0 ; i<6 ; i++)
            if(i!=5)
                printf("%d ", ans[i]);
            else
                printf("%d\n", ans[i]);
        return;
    }
    for(int i=cur ; i<k ;  i++){
        if(!visit[cur][lucky[i]] && !visit[lucky[i]][cur]){
            visit[cur][lucky[i]] = true, visit[lucky[i]][cur] = true;
            ans[layer] = lucky[i];
            lottery(i+1, layer+1);
            visit[cur][lucky[i]] = false, visit[lucky[i]][cur] = false;
        }
    }
}
