#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

bool isok(int);

int main()
{
    int N, flag=0;

    while(scanf("%d", &N)!=EOF){
        int lucky[10000];
        int num_lucky=0;

        for(int i=0 ; i<N ; i++){
            if(i>0 && (i%3)!=0 && (i%7)!=0 && isok(i)){
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

bool isok(int num)
{
    char str[10005];
    sprintf(str, "%d", num);

    int length = strlen(str);
    for(int i=0 ; i<length ; i++){
        if(str[i]=='3' || str[i]=='7')
            return false;
    }
    return true;
}
