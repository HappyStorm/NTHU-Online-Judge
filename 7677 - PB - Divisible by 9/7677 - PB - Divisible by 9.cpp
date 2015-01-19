#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int n, p, q, r, numarr[20], lp, lq;
char temp[20];
long long ans;
bool visit[15][10];
bool accept[15][15];
void div_counter(int, int);
bool div9(int[]);
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d %d", &n, &p, &q, &r);
        memset(numarr, 0, sizeof(numarr));
        memset(visit, false, sizeof(visit));
        memset(accept, false, sizeof(accept));
        ans = 0;
        div_counter(0,0);
        printf("%lld\n", ans);
    }
    return 0;
}

void div_counter(int cur, int layer)
{
    if(layer==n){
        if(div9(numarr))
            ans++;
        return;
    }
    if(!visit[cur][p]){
        visit[cur][p] = true;
        numarr[cur] = p;
        div_counter(cur+1, layer+1);
        visit[cur][p] = false;
    }
    if(!visit[cur][q]){
        visit[cur][q] = true;
        numarr[cur] = q;
        div_counter(cur+1, layer+1);
        visit[cur][q] = false;
    }
    if(!visit[cur][r]){
        visit[cur][r] = true;
        numarr[cur] = r;
        div_counter(cur+1, layer+1);
        visit[cur][r] = false;
    }
}

bool div9(int* num)
{
    int sum=0;
    for(int i=0 ; i<n ; i++)
        sum+=num[i];
    if(sum%9==0)
        return true;
    else
        return false;
}
