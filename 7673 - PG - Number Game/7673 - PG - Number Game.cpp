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

int main()
{
    int N;
    while(~scanf("%d", &N)){
        int num[1000+10], gcd=0;
        for(int i=0 ; i<N ; i++)
            scanf("%d", &num[i]);
        gcd = __gcd(num[0],num[1]);
        for(int i=2 ; i<N ; i++)
            gcd = __gcd(gcd, num[i]);
        printf("%d\n", gcd*N);
    }
    return 0;
}
