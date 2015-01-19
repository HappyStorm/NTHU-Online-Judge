#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
    int test, times=1;
    scanf("%d", &test);
    while(test--){
        int B, C, N, temp;
        scanf("%d %d %d", &B, &C, &N);
        priority_queue<int> bag;
        printf("Case #%d:\n", times++);
        for(int i=0 ; i<C ; i++)
            scanf("%d", &temp), bag.push(temp);
        for(int i=0 ; i<N ; i++){
            scanf("%d", &temp);
            if(temp>0){
                if(bag.size()<B)
                    printf("Take %d\n", temp), bag.push(temp);
                else
                    if(bag.top()>temp)
                        printf("Throw %d, take %d\n", bag.top(), temp), bag.pop(), bag.push(temp);
                    else
                        printf("Ignore %d\n", temp);
            }
            else{
                if(bag.size()>0)
                    printf("Use %d to defeat monster\n", bag.top()), bag.pop();
                else
                    printf("No stones, YLC flees\n");
            }
        }
    }
    return 0;
}
