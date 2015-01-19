#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3;
    while(~scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3)){
        long long cx = (y3-y2)*(x1*x1+y1*y1-x2*x2-y2*y2) - (y1-y2)*(x3*x3+y3*y3-x2*x2-y2*y2);
        long long px = 2*(x1-x2)*(y3-y2) - 2*(y1-y2)*(x3-x2);
        long long cy = (x1-x2)*(x3*x3+y3*y3-x2*x2-y2*y2) - (x3-x2)*(x1*x1+y1*y1-x2*x2-y2*y2);
        long long py = 2*(x1-x2)*(y3-y2) - 2*(y1-y2)*(x3-x2);
        if(cx%px==0 && cy%py==0)
            printf("%lld %lld\n", cx/px, cy/py);
        else
            printf("-1\n");
    }

}
