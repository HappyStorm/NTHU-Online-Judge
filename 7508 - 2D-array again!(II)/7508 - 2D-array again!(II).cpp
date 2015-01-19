#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#define MAX 47000
using namespace std;
int n, q, a1, a2, b1, b2, t, prime[MAX], num[1000+10][1000+10];


void prime_table()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = 0, prime[1] = 0;
    for(int i=2 ; i<=1000 ; i++){
        if(prime[i]){
            for(int j=i*i ; j<=1000 ; j+=i)
                prime[j] = 0;
        }
    }
}

int main()
{
    int times=1, ans;
    prime_table();
    while(~scanf("%d %d", &n, &q)){
        if(n==0 && q==0) break;
        memset(num, 0, sizeof(num));
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                scanf("%d", &t);
                if(prime[t]) num[i][j] = 1;
                num[i][j]+=(num[i-1][j]+num[i][j-1]-num[i-1][j-1]);
            }
        }
        printf("Case #%d:\n", times++);
        for(int i=0 ; i<q ; i++){
            scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
            ans = num[b1][b2] - num[a1-1][b2] - num[b1][a2-1] + num[a1-1][a2-1];
            printf("%d\n", ans);
        }
    }
    return 0;
}
