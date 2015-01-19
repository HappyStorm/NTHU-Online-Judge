#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#define M 1000000007
using namespace std;


long long* mymode(long long, long long);
long long trans[4]={2, 1, 1, 3};
int main()
{
    long long a0, b0, t;
    while(~scanf("%lld %lld %lld", &a0, &b0, &t)){
        long long *matrix = mymode(t, M);
        long long ta = a0, tb = b0;
        a0 = (matrix[0]*ta + matrix[1]*tb) % M;
        b0 = (matrix[2]*ta + matrix[3]*tb) % M;
        printf("%lld %lld\n", a0, b0);
        free(matrix);
    }
    return 0;
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
        long long t0 = ans[0], t1 = ans[1], t2 = ans[2], t3 = ans[3];
        if(pow%2){
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
            ans[0] = (t0*t0 + t1*t2) % mode;
            ans[1] = (t0*t1 + t1*t3) % mode;
            ans[2] = (t2*t0 + t3*t2) % mode;
            ans[3] = (t2*t1 + t3*t3) % mode;
            return ans;
        }
    }
    free(ans);
}
