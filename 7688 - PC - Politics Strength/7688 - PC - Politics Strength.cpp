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
#include <set>
using namespace std;
set<int> hint;
int N, M, a, b, R, talk[1000+5][1000+5], ori, t;
int people[1000+5], check;
double pa, pb;
bool visit[1000+5];
queue<int> all;

void color();
int main()
{
    int times=1;
    while(~scanf("%d %d", &N, &M)){
        hint.clear();
        pa=0, pb=0;
        memset(talk, 0, sizeof(talk));
        memset(people, 0, sizeof(people));
        memset(visit, false, sizeof(visit));
        while(!all.empty()) all.pop();
        for(int i=0 ; i<M ; i++){
            scanf("%d %d %d", &a, &b, &R);
            if(R>50)
                talk[a][b] = 1, talk[b][a] = 1;
            else
                talk[a][b] = -1, talk[b][a] = -1;
            hint.insert(a), hint.insert(b);
        }
        if(hint.size()!=N)
            printf("Case #%d: Ambiguous\n", times++);
        else{
            check = 0;
            color();
            if(check)
                printf("Case #%d: Ambiguous\n", times++);
            else{
                for(int i=1 ; i<=N ; i++)
                    if(people[i])
                        pa++;
                    else
                        pb++;
                pa = pa/hint.size() * 100;
                pb = pb/hint.size() * 100;
                if(pa>pb)
                    printf("Case #%d: %.2f%% %.2f%\n", times++, pb, pa);
                else
                    printf("Case #%d: %.2f%% %.2f%\n", times++, pa, pb);
            }
        }
    }
    return 0;
}

void color()
{
    people[1] = 0, visit[1] = true, all.push(1);
    while(!all.empty()){
        ori = all.front();
        all.pop();
        for(int i=1 ; i<=N ; i++){
            if(talk[ori][i] && !visit[i]){
                if(talk[ori][i]==1)
                    people[i] = people[ori];
                else
                    people[i] = !people[ori];
                visit[i] = true;
                all.push(i);
            }
            else if(talk[ori][i] && visit[i]){
                if(talk[ori][i]==1)
                    if(people[ori]!=people[i])
                        check = 1;
                else
                    if(talk[ori][i]==-1)
                        if(people[ori]==people[i])
                            check = 1;
                if(check)
                    break;
            }
        }
    }
}

