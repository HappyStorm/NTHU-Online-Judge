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

int mode[1000000+5];
int main()
{
    int num;
    while(~scanf("%d", &num) && num){
        memset(mode, 0, sizeof(mode));
        int temp, flag=0, ans=0;
        for(int i=0 ; i<num ; i++)
            scanf("%d", &temp), mode[temp]++;
        for(int i=1 ; i<=1000000 ; i++)
            if(mode[i]>flag)
                ans = i, flag = mode[i];
        printf("%d\n", ans);
    }
    return 0;
}
