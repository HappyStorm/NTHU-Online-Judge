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
struct wheel{
    int number[4], time;
};
queue<wheel> wheelque;
wheel st, tw, ori;
int N, n, forbid, ans, start[4], tar[4], spin[2]={1,-1}, visit[10000];
bool safe(int[]);
bool finish(int[]);
int bignumber(int[]);
int findwheel();
vector<wheel> forbd;
int main()
{
    scanf("%d", &N);
    while(N--){
        scanf("%d %d %d %d", &st.number[0], &st.number[1], &st.number[2], &st.number[3]), st.time=0;
        scanf("%d %d %d %d", &tar[0], &tar[1], &tar[2], &tar[3]);
        scanf("%d", &forbid);
        forbd.clear();
        for(int i=0 ; i<forbid ; i++)
            scanf("%d %d %d %d", &tw.number[0], &tw.number[1], &tw.number[2], &tw.number[3]), forbd.push_back(tw);
        memset(visit, 0, sizeof(visit));
        ans = findwheel();
        printf("%d\n", ans);
        while(!wheelque.empty())
            wheelque.pop();
    }
    return 0;
}

bool safe(int* num)
{
    for(int i=0 ; i<forbd.size() ; i++){
        if(num[0]==forbd[i].number[0] && num[1]==forbd[i].number[1] &&
           num[2]==forbd[i].number[2] && num[3]==forbd[i].number[3])
           return false;
    }
    return true;
}

int findwheel()
{
    wheelque.push(st);
    visit[bignumber(st.number)] = 1;
    while(!wheelque.empty()){
        ori = wheelque.front();
        if(finish(ori.number)) return ori.time;
        wheelque.pop();
        for(int i=0 ; i<8 ; i++){
            tw = ori;
            if(i%2) tw.number[i/2] = (ori.number[i/2]+spin[i%2]+10) % 10;
            else tw.number[i/2] = (ori.number[i/2]+spin[i%2]) % 10;
            tw.time = ori.time+1;
            if(!safe(tw.number) || visit[bignumber(tw.number)]) continue;
            visit[bignumber(tw.number)] = 1;
            wheelque.push(tw);
        }
    }
    return -1;
}

bool finish(int* num)
{
    if(num[0]==tar[0] && num[1]==tar[1] &&
       num[2]==tar[2] && num[3]==tar[3])
        return true;
    return false;
}

int bignumber(int* num)
{
    return num[0]*1000 + num[1]*100 + num[2]*10 + num[3];
}
