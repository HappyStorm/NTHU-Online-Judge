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
long long trans[4]={2, 1, 1, 3};
int main()
{
    long long a, r, n, m;
    while(~scanf("%lld %lld %lld %lld", &a, &r, &n, &m)){
        trans[0] = 1, trans[1] = r, trans[2] = 0, trans[3] = r;
        long long *matrix = mymode(n-1, m);
        long long ta = a, ts = a, s;
        s = (matrix[0]*ts + matrix[1]*ta) % m;
        a = (matrix[2]*ts + matrix[3]*ta) % m;
        printf("%lld\n", s);
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
