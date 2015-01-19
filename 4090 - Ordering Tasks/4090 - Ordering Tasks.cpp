#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;
int m, n, ti, tj, degree[100+10];
bool con[100+10][100+10];
int main()
{
    while(~scanf("%d %d", &n, &m)){
        if(n==0 && m==0)
            break;
        memset(degree, 0, sizeof(degree));
        memset(con, false, sizeof(con));
        for(int i=0 ; i<m ; ++i){
            scanf("%d %d", &ti, &tj);
            if(!con[ti][tj])degree[tj]++;
            con[ti][tj] = true;
        }
        for(int i=1, ct=0 ; i<=n ; ++i, ++ct){
            int s=1;
            while(s<=n && degree[s]!=0) ++s;
            if(s==n+1) break;
            degree[s] = -1;
            if(ct<n-1)
                printf("%d ", s);
            else
                printf("%d\n", s);
            for(int j=1 ; j<=n ; j++)
                if(con[s][j])
                    degree[j]--;
        }
    }
    return 0;
}
