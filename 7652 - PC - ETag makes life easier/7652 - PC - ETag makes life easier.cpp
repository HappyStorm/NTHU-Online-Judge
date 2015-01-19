#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        vector<int> station;
        int sta;
        scanf("%d", &sta);
        long long total=0;
        for(int i=0 ; i<sta; i++){
            int temp;
            scanf("%d", &temp);
            total+=temp;
            station.push_back(temp);
        }
        int target, target1 = total/sta, target2 = total/sta + 1;
        long long ans, ans1=0, ans2=0;
        for(int i=0 ; i<sta ; i++){
            ans1 = ans1 + (target1-station[i])*(target1-station[i]);
            ans2 = ans2 + (target2-station[i])*(target2-station[i]);
        }
        if(ans1>ans2)
            ans = ans2, target = target2;
        else
            ans = ans1, target = target1;
        printf("%lld %d\n", ans, target);
    }
    return 0;
}


