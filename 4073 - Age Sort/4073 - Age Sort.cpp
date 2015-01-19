#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int num;
    while(EOF!=scanf("%d", &num)){
        if(num==0)
            break;
        int age[100+10]={0};
        for(int i=0 ; i<num ; i++){
            int temp;
            scanf("%d", &temp);
            age[temp]++;
        }
        int flag=0;
        for(int i=1 ; i<=100 ; i++){
            if(age[i]!=0 && flag==0){
                for(int j=0 ; j<age[i] ; j++)
                    printf("%d", i);
                flag=1;
            }
            else if(age[i]!=0 && flag==1){
                for(int j=0 ; j<age[i] ; j++)
                    printf(" %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
