#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <list>
bool prime[100000];
int p, q, r, s, t, u;

double cal(double, int, int, int, int, int, int);
int main()
{
    while(~scanf("%d %d %d %d %d %d",&p, &q, &r, &s, &t, &u)){
        double low=0, high=1, mid;
        if(cal(low, p, q, r, s, t, u) * cal(high, p, q, r, s, t, u) > 0)
            puts("No solution");
        else{
            while((high-low)>1e-8){
                mid = (low+high)/2;
                if(cal(low, p, q, r, s, t, u) * cal(mid, p, q, r, s, t, u) > 0)
                    low = mid;
                else if(cal(mid, p, q, r, s, t, u) * cal(high, p, q, r, s, t, u) > 0)
                    high = mid;
            }
            printf("%.4f\n", high);
        }
    }
    return 0;
}

double cal(double x, int p, int q, int r, int s, int t, int u)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

