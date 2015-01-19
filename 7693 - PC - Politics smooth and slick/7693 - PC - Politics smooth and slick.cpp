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
int N, M, a, b, R, talk[1000+50][1000+50], ori;
int people[1000+50], check;
bool visit[1000+50];
queue<int> all;

void color();
int main()
{
    int times=1;
    while(~scanf("%d %d", &N, &M)){
        memset(talk, 0, sizeof(talk));
        memset(people, -1, sizeof(people));
        memset(visit, false, sizeof(visit));
        while(!all.empty()) all.pop();
        for(int i=0 ; i<M ; i++){
            scanf("%d %d %d", &a, &b, &R);
            if(R>50)
                talk[a][b] = 1, talk[b][a] = 1;
            else
                talk[a][b] = -1, talk[b][a] = -1;
        }
        check = 0;
        color();
        if(check)
            printf("Case #%d: Eight face discovered!\n", times++);
        else
            printf("Case #%d: I don't know!\n", times++);

    }
    return 0;
}

void color()
{
    people[1] = 1, visit[1] = true, all.push(1);
    while(!all.empty()){
        ori = all.front();
        all.pop();
        for(int i=1 ; i<=N ; i++){
            if(talk[ori][i] && !visit[i]){
                if(talk[ori][i]==1){
                    people[i] = people[ori];
                }
                else{
                    people[i] = !people[ori];
                }
                visit[i] = true;
                all.push(i);
            }
            else if(talk[ori][i] && visit[i]){
                if(talk[ori][i]==1){
                    if(people[ori]!=people[i]){
                        check = 1;
                    }
                }
                else{
                    if(people[ori]==people[i]){
                        check = 1;
                    }
                }
            }
        }
    }
}
