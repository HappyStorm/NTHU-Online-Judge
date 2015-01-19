#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct station{
    long long dis, fuel;
}Station;

bool cmpbyDis(Station a, Station b)
{
    return a.dis<b.dis;
}

int main()
{
    int N;
    while(~scanf("%d", &N)){
        vector<Station> staList;
        long long d, f, totalFuel=0;
        Station s;
        for(int i=0 ; i<N ; i++){
            scanf("%lld %lld", &d, &f);
            totalFuel+=f;
            s.dis = d, s.fuel = f;
            staList.push_back(s);
        }
        long long L, P;
        scanf("%lld %lld", &L, &P);
        if(totalFuel+P < L)
            printf("-1\n");
        else{
            for(int i=0 ; i<N ; i++)
                staList[i].dis = L - staList[i].dis;
            sort(staList.begin(), staList.end(), cmpbyDis);
            s.dis = L, s.fuel = 0;
            staList.push_back(s);
            long long location=0, record=0, times=0, curfuel=P, arrive=1;
            priority_queue<int> staStop;
            while(record<N+1){
                while(curfuel<staList[record].dis && !staStop.empty())
                    curfuel+=staStop.top(), staStop.pop(), times++;
                if(curfuel<staList[record].dis){
                    arrive = 0;
                    break;
                }
                staStop.push(staList[record].fuel);
                record++;
            }
            if(arrive)
                printf("%lld\n", times);
            else
                printf("-1\n");
        }
    }
    return 0;
}
