
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
#define M 100000007
using namespace std;

long long bigmod(long long, long long);

int main()
{
    int test, flag=1;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        long long temp, value=0;
        for(int i=0 ; i<n ; i++){
            scanf("%lld", &temp);
            value+=((2*(bigmod(temp,temp)%M))%M);
            value = value % M;
        }
        printf("Case #%d\n%lld\n", flag++, value%M);
    }
    return 0;
}

long long bigmod(long long base, long long pow)
{
    if(pow==0)
        return 1;
    else if(pow==1)
        return base % M;
    else{
        long long ans = bigmod(base, pow/2) % M;
        if(pow % 2==0)
            return (ans * ans) % M;
        else
            return (((ans * ans)%M) * base) % M;
    }
}
