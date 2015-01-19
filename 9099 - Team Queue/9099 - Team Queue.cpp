#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long all[1500000];
bool exist[2000];
int main()
{
    int test, times=1;
    scanf("%d", &test);
    while(test--){
        int team, op;
        scanf("%d %d", &team, &op);
        if(times!=1)
            putchar(10);
        printf("Case %d:\n", times++);
        memset(all, 0, sizeof(all));
        memset(exist, false, sizeof(exist));

        long long people, temp;;
        queue<long long> total;
        queue<long long> allteam[1001];
        for(int i=1 ; i<=team ; i++){
            scanf("%lld", &people);
            for(int j=0 ; j<people ; j++)
                scanf("%lld", &temp), all[temp] = i;
        }

        char input[10];
        getchar();
        for(int i=0 ; i<op ; i++){
            scanf("%s", input);
            if(input[1]=='U'){
                int x;
                scanf("%lld", &x);
                if(all[x]!=0){
                    allteam[all[x]].push(x);
                    if(!exist[all[x]])
                        total.push(all[x]), exist[all[x]] = true;
                }
                else
                    allteam[0].push(x), total.push(0);
            }
            else if(input[1]=='O'){
                if(!allteam[total.front()].empty()){
                    printf("%lld\n", allteam[total.front()].front());
                    allteam[total.front()].pop();
                }
                else{
                    exist[total.front()] = false, total.pop();
                    printf("%lld\n", allteam[total.front()].front());
                    allteam[total.front()].pop();
                }
            }
        }
    }
    return 0;
}
