#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int n, q;
        scanf("%d %d", &n, &q);
        int num[10000+10]={0};
        for(int i=1 ; i<=n ; i++)
            scanf("%d", &num[i]);
        while(q--){
            int a, b, ans=0;
            scanf("%d %d", &a, &b);
            for(int i=a ; i<=b ; i++)
                ans+=num[i];
            printf("%d\n", ans);
        }
    }
}
