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
int N, Root, a, b, ori, temp, first;
bool visit[1000+5];
vector<int> node[1000+5];
queue<int> tree;

void trace();
int main()
{
    int test, times=1;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &N, &Root);
        memset(visit, false, sizeof(visit));
        tree.push(Root);
        for(int i=1 ; i<=N ; i++)
            node[i].clear();
        for(int i=0 ; i<N-1 ; i++){
            scanf("%d %d", &a, &b);
            node[a].push_back(b);
            node[b].push_back(a);
            sort(node[a].begin(), node[a].end());
            sort(node[b].begin(), node[b].end());
        }
        if(times!=1) putchar(10);
        printf("Case %d: %d", times++, tree.front());
        visit[tree.front()] = true;
        trace();
        putchar(10);
    }

    return 0;
}
void trace()
{
    while(!tree.empty()){
        ori = tree.front();
        tree.pop();
        for(int i=0 ; i<node[ori].size() ; i++){
            if(visit[node[ori][i]]) continue;
            visit[node[ori][i]] = true;
            tree.push(node[ori][i]);
            printf(" %d", node[ori][i]);
        }
    }
}
