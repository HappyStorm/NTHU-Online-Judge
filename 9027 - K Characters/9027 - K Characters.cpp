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
int com, len;
char ans[11], input[125];
bool visit[125];
void combination(int, int);
int main()
{
    int test;
    scanf("%d", &test), getchar();
    while(test--){
        memset(input, '\0', sizeof(input));
        memset(visit, false, sizeof(visit));
        scanf("%s %d", input, &com);
        len = strlen(input);
        sort(input, input+len);
        combination(0, 0);
        putchar(10);
    }
    return 0;
}

void combination(int cur, int layer)
{
    if(layer==com){
        for(int i=0 ; i<com ; i++)
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
