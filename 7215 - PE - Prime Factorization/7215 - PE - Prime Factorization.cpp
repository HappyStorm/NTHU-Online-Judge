#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#define MAX 50000
using namespace std;
bool prime[MAX];
int prime_num=0;
void prime_table()
{
    memset(prime, true, sizeof(prime));
    prime[0] = false, prime[1] = false;
    int m = 46341;
    for(int i=2 ; i<=m ; i++){
        if(prime[i]){
            prime_num++;
            for(long long j=i*i ; j<=MAX ; j=j+i)
                prime[j] = false;
        }
    }
}
void factor(int);

int main()
{
    prime_table();
    int X;
    while(~scanf("%d", &X))
        factor(X);
}

void factor(int n)
{
    int ct=0, last=0;
    int x = n, plist[50000], ppow[50000];
    memset(plist, 0, sizeof(plist));
    memset(ppow, 0, sizeof(ppow));
    for(int i=2 ; i<=46341 ; i++){
        if(prime[i] && (x%i==0)){
            ppow[i] = 0;
            while(x%i==0)
                x = x/i, ppow[i]++;
            plist[i] = 1;
            last = i;
        }
        ct = i;
    }
    //printf("Num= %d, Last= %d, Ct= %d\n", num, last, ct);
    if(x>1)
        ppow[ct] = 1, plist[ct] = 1;
    for(int i=2 ; i<=last ; i++){
        if(plist[i] && i!=last)
            printf("%d^%d*", i, ppow[i]);
        else if(plist[i] && i==last)
            printf("%d^%d\n", i, ppow[i]);
    }
    if(x==n)
        printf("%d^1\n", x);
}
