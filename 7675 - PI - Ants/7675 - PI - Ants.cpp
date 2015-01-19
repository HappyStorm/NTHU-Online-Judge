#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int L, n;
        scanf("%d %d", &L, &n);
        long long temp, left, right;
        long long minT=0, maxT=0, tempmax, tempmin;
        long long dis=99999;
        for(int i=0 ; i<n ; i++){
            scanf("%lld", &temp);
            left = temp, right = L-temp;
            tempmax = max(left, right);
            tempmin = min(left, right);
            maxT = max(maxT, tempmax);
            if(abs(temp-L/2)<=dis)
                minT = max(minT, tempmin), dis = abs(temp-L/2);
        }
        printf("%lld %lld\n", minT, maxT);
    }
    return 0;
}



