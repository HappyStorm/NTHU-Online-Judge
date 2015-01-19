#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char input[100001]={0};
    while(gets(input)!=NULL){
        int half_length = strlen(input)/2, length = strlen(input), flag=1;
        for(int i=0 ; i<half_length ; i++)
            if(input[i]!=input[length-i-1]){
                flag=0;
                break;
            }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
