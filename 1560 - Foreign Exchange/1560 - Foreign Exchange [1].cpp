#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int start[500000+5], target[500000+5];
int main()
{
    int people;
    while(EOF!=scanf("%d", &people) && people){
        int flag=1;
        for(int i=0 ; i<people ; i++)
            scanf("%d %d", &start[i], &target[i]);
        sort(start, start+people), sort(target, target+people);
        for(int i=0 ; i<people ; i++)
            if(start[i]!=target[i]){
                flag=0;
                break;
            }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

