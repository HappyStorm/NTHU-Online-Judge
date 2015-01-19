#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int gcd(int, int);
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int a, b, g;
        scanf("%d %d", &a, &b);
        g = gcd(a, b);
        printf("%d/%d\n", a/g, b/g);
    }
    return 0;
}


int gcd(int a, int b)
{
    int remain = max(a, b) % min(a, b), ans;
    if(remain!=0){
        while(remain!=0){
            if(a>b)
                a = remain, remain = b%a, ans = a;
            else
                b = remain, remain = a%b, ans = b;
        }
        return ans;
    }
    else
        return min(a, b);
}
