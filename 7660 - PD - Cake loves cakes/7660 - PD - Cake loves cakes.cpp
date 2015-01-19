#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int point[500000+10];
char input[500000+10];
int main()
{
    int test, time=1;
    scanf("%d", &test), getchar();
    while(test--){
        memset(input, '\0', sizeof(input));
        memset(point, 0, sizeof(point));
        gets(input);
        //printf("%s\n", input);
        int len = strlen(input), prefix=0;
        for(int i=0 ; i<len ; i++){
            if(input[i]=='1')
                point[i]  = ++prefix;
            else
                point[i]  = prefix;
        }
        //for(int i=0 ; i<len ; i++)
        //    printf("%d", point[i]);
        //putchar(10);
        int Q, a, b, dis;
        scanf("%d",&Q);
        printf("Case %d:\n", time++);
        for(int i=0 ; i<Q ; i++){
            scanf("%d %d", &a, &b), a-=1, b-=1;
            if(a==0)
                dis = point[b]-point[a];
            else
                dis = point[b]-point[a];
            //printf("[a=%d]= %d  [b=%d]= %d  Dis= %d\n", a, point[a], b, point[b], dis);
            if((dis==b-a && input[a]==input[b]) || (dis==0 && input[a]==input[b]) || a==b)
                puts("Yes");
            else
                puts("No");
        }
        getchar();
    }
    return 0;
}
