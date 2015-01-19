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


long long* mymode(long long, long long);
long long pow2(long long);
long long trans[4]={1, 1, 1, 0};
int main()
{
    long long n, M;
    while(~scanf("%lld %lld", &n, &M)){
        long long mode = pow2(M);
        long long *matrix = mymode(n-1, mode);
        long long ans;
        ans = (matrix[0]) % mode;
        printf("%lld\n", ans);
        free(matrix);
    }
    return 0;
}

long long pow2(long long t)
{
    long long ans = 1;
    for(int i=0 ; i<t ; i++)
        ans*=2;
    return ans;
}

long long* mymode(long long pow, long long mode)
{
    long long *ans = (long long*)malloc(4*sizeof(long long));
    if(pow==0){
        ans[0] = 1, ans[1] = 0, ans[2] = 0, ans[3] = 1;
        return ans;
    }
    else if(pow==1){
        memcpy(ans, trans, sizeof(trans));
        return ans;
    }
    else{
        ans = mymode(pow/2, mode);
        if(pow%2){
            long long t0 = ans[0], t1 = ans[1], t2 = ans[2], t3 = ans[3];
            ans[0] = (t0*t0 + t1*t2) % mode;
            ans[1] = (t0*t1 + t1*t3) % mode;
            ans[2] = (t2*t0 + t3*t2) % mode;
            ans[3] = (t2*t1 + t3*t3) % mode;
            t0 = ans[0], t1 = ans[1], t2 = ans[2], t3 = ans[3];
            ans[0] = (t0*trans[0] + t1*trans[2]) % mode;
            ans[1] = (t0*trans[1] + t1*trans[3]) % mode;
            ans[2] = (t2*trans[0] + t3*trans[2]) % mode;
            ans[3] = (t2*trans[1] + t3*trans[3]) % mode;
            return ans;
        }
        else{
            long long t0 = ans[0], t1 = ans[1], t2 = ans[2], t3 = ans[3];
            ans[0] = (t0*t0 + t1*t2) % mode;
            ans[1] = (t0*t1 + t1*t3) % mode;
            ans[2] = (t2*t0 + t3*t2) % mode;
            ans[3] = (t2*t1 + t3*t3) % mode;
            return ans;
        }
    }
}

