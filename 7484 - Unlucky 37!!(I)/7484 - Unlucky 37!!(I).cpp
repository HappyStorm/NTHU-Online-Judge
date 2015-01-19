#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int N, flag=0;

    while(scanf("%d", &N)!=EOF){
        int lucky[10000];
        int num_lucky=0;

        for(int i=0 ; i<N ; i++){
            if(i>0 && (i%3)!=0 && (i%7)!=0){
                lucky[num_lucky]=i;
                num_lucky++;
            }
        }

        if(flag!=0)
            printf("\n");

        for(int i=0 ; i<num_lucky ; i++){
            if(i!=num_lucky-1)
                printf("%d ", lucky[i]);
            else
                printf("%d\n", lucky[i]);
        }
        flag++;
    }
    return 0;
}
