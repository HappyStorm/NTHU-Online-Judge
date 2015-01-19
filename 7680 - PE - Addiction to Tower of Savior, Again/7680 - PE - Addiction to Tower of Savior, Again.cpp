#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int X, Y;

struct bag{
    long long stone, time;
};
bag st, tb, ori;
queue<bag> hand;
bool visit[10000000+5];
int cal();
int main()
{
    while(~scanf("%d %d", &X, &Y)){
        while(!hand.empty())
            hand.pop();
        memset(visit, false, sizeof(visit));
        st.stone=X, st.time=0;
        hand.push(st);
        int ans = cal();
        printf("%d\n", ans);
    }
    return 0;
}

int cal()
{
    visit[X] = true;
    while(!hand.empty()){
        ori = hand.front(), hand.pop();
        if(ori.stone==Y) return ori.time;
        tb.stone = ori.stone+1, tb.time = ori.time+1;
        if(!visit[tb.stone] && tb.time<=20){
            visit[tb.stone] = true;
            hand.push(tb);
        }
        tb.stone = ori.stone*2, tb.time = ori.time+1;
        if(tb.stone<=1000000){
            if(!visit[tb.stone] && tb.time<=20){
                visit[tb.stone] = true;
                hand.push(tb);
            }
        }
    }
}

