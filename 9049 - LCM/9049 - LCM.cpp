#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int a, b;
        scanf("%d %d", &a, &b);
        long long gcd = __gcd(a, b);
        long long lcm = a/gcd*b;
        printf("%lld\n", lcm);
    }
    return 0;
}
