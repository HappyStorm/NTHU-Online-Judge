#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);

    while(test--){
        char temp[100000], isend;
        int index[50000];

        int num=0;
        while(scanf("%d", &index[num++])){
            if( (isend=getchar()) != ' ')
                break;
        }

        char numbers[50000][20];
        for(int i=0 ; i<num ; i++){
            scanf("%s", numbers[index[i]-1]);
        }
        for(int i=0 ; i<num ; i++){
            printf("%s\n", numbers[i]);
        }
        if(test)
        printf("\n");
    }
    return 0;
}
