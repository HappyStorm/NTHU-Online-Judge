#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct people{
    char name[25];
    long long value;
};
bool cmp(people a, people b)
{
    return a.value<b.value;
}
int main()
{
    int N, Q, flag=1;
    while(~scanf("%d %d", &N, &Q)){
        vector<people> rich;
        int X, Y, Z;
        long long value;
        char name[25];
        people p;
        for(int i=0 ; i<N ; i++){
            value = 0;
            scanf("%s", name);
            scanf("%d%*c%d%*c%d", &X, &Y, &Z);
            value+=(1000000*X + 1000*Y + Z);
            strcpy(p.name, name), p.value = value;
            rich.push_back(p);
        }
        sort(rich.begin(), rich.end(), cmp);
        long long query=0;
        printf("----Report %d----\n", flag++);
        for(int i=0 ; i<Q ; i++){
            scanf("%lld", &query);
            int low=0, high=N-1, mid=0;
            while(low<high){
                mid = (low+high)/2;
                if(rich[mid].value>query)
                    high = mid , mid = high;
                else if(rich[mid].value<query)
                    low = mid+1, mid = low;
                else
                    break;
            }
            while(rich[mid].value>=query && mid>=0)
                mid--;
            printf("%lld %d\n", query, (N-1)-mid);
        }
    }
    return 0;
}
