#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

long long gcd(long long, long long);
int main()
{
    long long len1, len2;
    while(~scanf("%lld %lld", &len1, &len2)){
        long long GCD = gcd(len1, len2), ans = len1/GCD*len2;
        printf("%lld\n", ans);
    }
    return 0;
}

long long gcd(long long a, long long b)
{
    long long ans=1;
    while(true){
        if(a>b)
            ans = b, a = a%b;
        else if(a<b)
            ans = a, b = b%a;
        else
            return a;
        if(a==0 || b==0)
            break;
    }
    return ans;
}
