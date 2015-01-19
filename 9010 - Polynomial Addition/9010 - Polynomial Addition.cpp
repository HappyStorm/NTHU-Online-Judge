#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);

    while(test--){
        int p1, p2;
        scanf("%d %d", &p1, &p2);
        // p1=2, p2=3
        int poly1[1000]={0}, poly2[1000]={0};
        for(int i=p1 ; i>=0 ; i--)
            scanf("%d", &poly1[i]);
        for(int i=p2 ; i>=0 ; i--)
            scanf("%d", &poly2[i]);

        int panswer[1000]={0};
        int num = max(p1, p2);
        for(int i=num ; i>=0 ; i--){
            panswer[i] = poly1[i] + poly2[i];
            if(panswer[i]!=0 && i>0)
                printf("%d ", panswer[i]);
            else if(panswer[i]!=0 && i==0)
                printf("%d\n", panswer[i]);
            else if(panswer[i]==0 && i==0)
                printf("\n");
        }
    }
    return 0;
}
