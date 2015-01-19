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
int N, M, len, temp[11];
char ans[11], input[125];
bool visit[125];
void combination(int, int);
int main()
{
    int test, times=1;
    scanf("%d", &test), getchar();
    while(test--){
        printf("Case %d:\n", times++);
        memset(input, '\0', sizeof(input));
        memset(visit, false, sizeof(visit));
        scanf("%d %d", &N, &M);
        for(int i=0 ; i<N ; i++)
            scanf("%d", &temp[i]), input[i] = temp[i]+'0';
        len = strlen(input);
        sort(input, input+len);
        combination(0, 0);
    }
    return 0;
}

void combination(int cur, int layer)
{
    if(layer==M){
        for(int i=0 ; i<M ; i++)
            putchar(ans[i]);
        putchar(10);
        return;
    }
    char last='\0';
    for(int i=cur ; i<len ;  i++){
        if(!visit[i]){
            if(input[i]!=last){
                last = input[i];
                visit[i] = true;
                ans[layer] = input[i];
                combination(i+1, layer+1);
                visit[i] = false;
            }
        }
    }
}

