#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

bool check(int, int);

int L, N, M, stone[500000+10];
int main()
{
    while(~scanf("%d %d %d", &L, &N, &M)){
        if(N>0 && M>1){
            memset(stone, 0, sizeof(stone));
            stone[0] = 0;
            int mindis=0;
            for(int i=1 ; i<=N ; i++)
                scanf("%d", &stone[i]);
            stone[N+1] = L;
            sort(stone+1, stone+N+1);
            for(int i=1 ; i<=N+1 ; i++)
                mindis = max(mindis, stone[i]-stone[i-1]);

            int low=mindis, high=L, mid;
            while(low<high){
                mid = (low+high)/2;
                if(check(mid, M))
                    high = mid;
                else
                    low = mid + 1;
            }
            printf("%d\n", low);
        }
        else
            printf("%d\n", L);
    }
    return 0;
}

bool check(int jumpdis, int times)
{
    long long tempdis=0;
    int ct=0;
    for(int i=N+1 ; i>0 ; i--){
        int diff = stone[i] - stone [i-1];
        if(tempdis+diff>jumpdis)
            tempdis=0, ct++;
        tempdis = tempdis + diff;
        if(ct>times)
            break;
    }
    if(ct>=times)
        return false;
    else
        return true;
}


