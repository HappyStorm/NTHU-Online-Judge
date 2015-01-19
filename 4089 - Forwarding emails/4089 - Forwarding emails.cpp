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
int N, u, v, parent, ans, maximum, Martian[50000+5], visit[50000+5], chain[50000+5];

int trace(int, int);
int main()
{
    int test, times=1;
    scanf("%d", &test);
    while(test--){
        memset(Martian, 0, sizeof(Martian)), memset(visit, 0, sizeof(visit)), memset(chain, -1, sizeof(chain));
        scanf("%d", &N);
        for(int i=0 ; i<N ; i++)
            scanf("%d %d", &u, &v), Martian[u] = v;
        maximum=0, ans=0;
        for(int i=1 ; i<=N ; i++){
            if(chain[i]==-1) trace(i, 0);
            if(chain[i]>maximum) ans = i, maximum = chain[i];
        }
        printf("Case %d: %d\n", times++, ans);
    }
    return 0;
}

int trace(int cur, int people)
{
    int change=0, after=0;
    visit[cur] = 1;
    if(!visit[Martian[cur]] && Martian[cur]!=0)
        visit[Martian[cur]] = 1, after = trace(Martian[cur], people+1), change=1;
    visit[cur] = 0;
    if(change)
        return chain[cur] = people + after;
    else
        return chain[cur] = people;
}
