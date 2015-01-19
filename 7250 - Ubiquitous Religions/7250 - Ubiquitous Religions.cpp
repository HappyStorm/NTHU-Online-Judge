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
int n, m, religion;
vector<int> society[50000+5];
bool visit[50000+5];

int trace(int);
int main()
{
    int times=1;
    while(~scanf("%d %d", &n, &m)){
        if(n==0 && m==0)
            break;
        memset(visit, false, sizeof(visit));
        for(int i=0 ; i<30004 ; i++)
            society[i].clear();
        int a, b;
        for(int i=0 ; i<m ; i++){
            scanf("%d %d", &a, &b);
            society[a].push_back(b);
            society[b].push_back(a);
        }
        religion=0;
        for(int i=1 ; i<=n ; i++){
            if(!visit[i])
                visit[i] = true, trace(i), ++religion;
        }
        printf("Case %d: %d\n", times++, religion);
    }
    return 0;
}

int trace(int cur)
{
    for(int i=0 ; i<society[cur].size() ; i++){
        if(!visit[society[cur][i]]){
            visit[society[cur][i]] = true;
            trace(society[cur][i]);
        }
    }
}
