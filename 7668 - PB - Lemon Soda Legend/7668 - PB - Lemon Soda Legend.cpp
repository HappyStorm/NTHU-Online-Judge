#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
using namespace std;
int stk[1000000+5], appear[1000000+5];
long long connect;
vector<long long> soldier;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        memset(appear, 0, sizeof(appear)), memset(stk, 0, sizeof(stk));
        int N;
        scanf("%d", &N), soldier.clear();
        connect=0;
        int temp;
        for(int i=0 ; i<N ; i++)
            scanf("%d", &temp), soldier.push_back(temp);
        // Always point the top object's location + 1.
        long long top = 0;
        for(int i=0 ; i<N ; i++){
            while(top>0 && stk[top-1]<soldier[i]){
                connect+=appear[--top];
                if(top>0) connect++;
                if(appear[top]>1) appear[top++]--;
            }
            if(top>0 && stk[top-1]==soldier[i])
                appear[top-1]++;
            else
                stk[top] = soldier[i], appear[top++]=1; //puts("OK");
        }
        while(top>0){
            connect+=appear[--top]-1;
            if(top>0) connect++;
            if(appear[top]>1)
                appear[top++]--;
        }
        printf("%lld\n", connect);
    }
    return 0;
}
