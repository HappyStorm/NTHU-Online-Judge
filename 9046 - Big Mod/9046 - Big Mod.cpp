#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

long long mod(long long, long long, long long);

int main()
{
    long long B, P, M;
    while(EOF!=scanf("%lld %lld %lld", &B, &P, &M))
       printf("%lld\n", mod(B,P,M));
    return 0;
}

long long mod(long long base, long long pow, long long mode)
{
    if(pow==0)
        return 1;
    else if(pow==1)
        return base % mode;
    else{
        long long remain = mod(base, pow/2, mode);
        if(pow%2)
            return (remain * remain * base) % mode;
        else
            return (remain * remain) % mode;
    }
}
