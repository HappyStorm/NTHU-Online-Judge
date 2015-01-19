#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
using namespace std;

int main()
{
    int n, k;
    while(EOF!=scanf("%d %d", &n, &k)){
        int newk = min(n, n-k);
        long long answer = 1;
        for(int i=1 ; i<=newk ; i++)
            answer = answer * (n-newk+i)/i;
        if(n<k)
            answer = 0;
        printf("%lld\n", answer);
    }
    return 0;
}
