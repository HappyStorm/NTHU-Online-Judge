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
int N, Root, a, b, total;
set<int> all;
bool visit[1000+5];
vector<int> node[1000+5];

void trace(int);
int main()
{
    while(~scanf("%d", &N) && N){
        all.clear();
        memset(visit, false, sizeof(visit));
        for(int i=0 ; i<N ; i++){
            scanf("%d %d", &a, &b);
            node[a].push_back(b);
            node[b].push_back(a);
            sort(node[a].begin(), node[a].end());
            sort(node[b].begin(), node[b].end());
            all.insert(a), all.insert(b);
        }
        total = all.size();
        scanf("%d", &Root);
        visit[Root] = true;
        trace(Root);
        for(int i=1 ; i<=1000 ; i++)
            node[i].clear();
    }
    return 0;
}

void trace(int cur)
{
    if(total>1)
        printf("%d ", cur), --total;
    else if(total==1){
        printf("%d\n", cur), --total;
        return;
    }
    else
        return;
    for(int i=0 ; i<node[cur].size() ; i++){
        if(!visit[node[cur][i]]){
            visit[node[cur][i]] = true;
            trace(node[cur][i]);
        }
    }
}
