#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
    int N, Q, flag=1;
    while(~scanf("%d %d", &N, &Q)){
        map<string, long long> rich;
        int X, Y, Z;
        long long value;
        char name[25];
        for(int i=0 ; i<N ; i++){
            value = 0;
            scanf("%s", name);
            scanf("%d%*c%d%*c%d", &X, &Y, &Z);
            value+=(1000000*X + 1000*Y + Z);
            rich.insert(pair<string, long long>((string)name, value));
        }
        char query[25];
        map<string, long long>::iterator it;
        printf("----Report %d----\n", flag++);
        for(int i=0 ; i<Q ; i++){
            scanf("%s", query);
            it = rich.find((string)query);
            printf("%s %lld\n", query, it->second);
        }
    }
    return 0;
}
