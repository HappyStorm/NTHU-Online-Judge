#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int wa;
    while(scanf("%d", &wa)!=EOF){
        if(wa%2==0 && wa!=2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
