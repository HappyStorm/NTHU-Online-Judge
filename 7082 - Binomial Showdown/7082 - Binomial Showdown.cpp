#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	unsigned long long m, n, M, N;
	while(EOF!=scanf("%llu %llu", &m, &n)){
        unsigned long long ans=1;
        if(m==0 && n==0)
            break;
        n = min(m-n, n);
        if(m>n)
            for(int i=1 ; i<=n ; i++)
                ans = ans * (m-n+i)/i;
        else if(m==n)
            ans=1;
        else
            ans=0;
        printf("%llu\n", ans);
	}
	return 0;
}
