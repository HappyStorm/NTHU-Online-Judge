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
int N, R, degree[200+5], visit[200+5], graph[200+5][200+5];

void runpath(int);
int main()
{
    while(~scanf("%d %d", &N, &R)){
        memset(degree, 0, sizeof(degree)), memset(graph, 0, sizeof(graph));
        int a, b, oddnode=0, check=1;
        for(int i=0 ; i<R ; i++)
            scanf("%d %d", &a, &b), graph[a][b] = 1, graph[b][a] = 1, degree[a]++, degree[b]++;
        for(int i=0 ; i<N ; i++)
            if(degree[i]%2){
                oddnode++; break;}
        if(oddnode>0 || R<2)
            puts("Not Possible");
        else{
            memset(visit, 0, sizeof(visit));
            runpath(0);
            for(int i=0 ; i<N ; i++)
                if(!visit[i]){
                    check=0; break;}
            if(check)
                puts("Possible");
            else
                puts("Not Possible");
        }
    }
    return 0;
}

void runpath(int cur)
{
    visit[cur] = 1;
    for(int i=0 ; i<N ; i++)
        if(!visit[i] && graph[cur][i])
            runpath(i);
}
