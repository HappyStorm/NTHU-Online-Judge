#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int is_triangle(int*);

int main()
{
    int test;
    scanf("%d", &test);

    while(test--){
        int which=1;
        int side[3];
        for(int i=0 ; i<3 ; i++)
            scanf("%d", &side[i]);

        which = is_triangle(side);
        if(which==0)
            printf("Oh~NO!!\n");
        else if(which==1)
            printf("OK!\n");
        else if(which==2)
            printf("2 equal\n");
        else
            printf("3 equal\n");
    }
    return 0;
}

int is_triangle(int* side)
{
    for(int i=0; i<3 ; i++){
        for(int j=0 ; j<2 ; j++){
            if(side[j]>side[j+1]){
                int temp=side[j];
                side[j] = side[j+1];
                side[j+1] = temp;
            }
        }
    }
    int low = *(side), mid = *(side+1), high = *(side+2);
    if(abs(high-low)>=mid ||
       low<=0 || mid<=0 || high<=0)
        return 0;
    else{
        if(low==mid && mid==high)
            return 3;
        else if(low==mid || mid==high)
            return 2;
    }
    return 1;
}
