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

int people[1000+5], group[1000+5];
int main()
{
    int N, K;
    while(~scanf("%d", &N) && N){
        scanf("%d", &K);
        for(int i=0 ; i<N ; i++)
            people[i] = i;
        memset(group, 0, sizeof(group));
        int X, Y, much=0, many=0, temp;
        for(int i=0 ; i<K ; i++){
            scanf("%d %d", &X, &Y);
            if(people[X]!=people[Y]){
                if(people[X]!=X)
                    temp = people[X], people[Y] = temp;
                else if(people[Y]!=Y)
                    temp = people[Y], people[X] = temp;
                else
                    temp = min(people[X], people[Y]), people[X] = temp, people[Y] = temp;
                group[temp]++;
            }
        }
        for(int i=0 ; i<N ; i++)
            much = max(much, group[i]);
        for(int i=0 ; i<N ; i++)
            if(group[i] == much)
                many++;
        printf("%d\n", many);
    }
    return 0;
}
