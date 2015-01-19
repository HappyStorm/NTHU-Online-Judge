#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    getchar();
    while(test--){
        char input[100+10], child[100+10]={0}, parent[100+10]={0}, temp[100+10]={0};
        gets(input);
        int length = strlen(input), flag=0;
        for(int j=0, k=0 ; j<length ; j++){
            if(input[j]=='0' && flag==0);
            else if('1'<=input[j] && input[j]<='9' && flag==0)
                child[k++] = input[j], flag++;
            else if('0'<=input[j] && input[j]<='9' && flag!=0)
                child[k++] = input[j];
        }
        gets(temp);
        gets(input);
        length = strlen(input), flag=0;
        for(int j=0, k=0 ; j<length ; j++){
            if(input[j]=='0' && flag==0);
            else if('1'<=input[j] && input[j]<='9' && flag==0)
                parent[k++] = input[j], flag++;
            else if('0'<=input[j] && input[j]<='9' && flag!=0)
                parent[k++] = input[j];
        }
        gets(temp);
        int childlength = strlen(child), parentlength = strlen(parent);
        if(childlength==0 && parentlength==0)
            printf("0/0\n");
        else if(childlength==0)
            printf("0/%s\n", parent);
        else if(parentlength==0)
            printf("%s/0\n", child);
        else
            printf("%s/%s\n", child, parent);
    }
    return 0;
}
