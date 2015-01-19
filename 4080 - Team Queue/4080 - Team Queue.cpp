#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int all[1000000];
bool exist[1000];
int main()
{
    int team, times=1;
    while(~scanf("%d", &team)){
        if(team==0)
            break;
        printf("Scenario #%d\n", times++);
        memset(all, 0, sizeof(all));
        memset(exist, false, sizeof(exist));

        int people, temp;;
        queue<int> total;
        queue<int> allteam[1001];
        for(int i=1 ; i<=team ; i++){
            scanf("%d", &people);
            for(int j=0 ; j<people ; j++)
                scanf("%d", &temp), all[temp] = i;
        }

        char input[10];
        while(~scanf("%s", input)){
            if(input[0]=='S')
                break;
            else if(input[0]=='E'){
                int x;
                scanf("%d", &x);
                if(all[x]!=0){
                    allteam[all[x]].push(x);
                    if(!exist[all[x]])
                        total.push(all[x]), exist[all[x]] = true;
                }
                else
                    allteam[0].push(x), total.push(0);
            }
            else if(input[0]=='D'){
                if(!allteam[total.front()].empty()){
                    printf("%d\n", allteam[total.front()].front());
                    allteam[total.front()].pop();
                }
                else{
                    exist[total.front()] = false, total.pop();
                    printf("%d\n", allteam[total.front()].front());
                    allteam[total.front()].pop();
                }
            }
        }
        putchar(10);
    }
    return 0;
}
