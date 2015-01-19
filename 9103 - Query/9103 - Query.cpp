#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
    int N, times=1;
    while(~scanf("%d", &N)){
        if(N==0)
            break;
        if(times!=1)
            putchar(10);
        times++;
        map<long long, long long> num;
        long long temp, query;
        for(int i=0 ; i<N ; i++){
            scanf("%lld", &temp);
            num.insert(pair<long long, long long>(temp, temp));
        }
        map<long long, long long>::iterator it;
        int Q;
        scanf("%d", &Q);
        for(int i=0 ; i<Q ; i++){
            scanf("%lld", &query);
            it = num.find(query);
            if(it==num.end())
                puts("No");
            else
                puts("Yes");
        }
    }
}
