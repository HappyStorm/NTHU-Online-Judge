#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int num;
    while(EOF!=scanf("%d", &num)){
       int Xi[10000+10]={0};
       for(int i=0 ; i<num ; i++){
            int temp;
            scanf("%d", &temp);
            Xi[temp]++;
       }
       int flag=0;
        for(int i=0 ; i<10001 ; i++){
            if(Xi[i]!=0 && flag==0){
                printf("%d %d", Xi[i], i);
                flag=1;
            }
            else if(Xi[i]!=0 && flag==1)
                printf(" %d %d", Xi[i], i);
        }
        printf("\n");
    }
    return 0;
}
