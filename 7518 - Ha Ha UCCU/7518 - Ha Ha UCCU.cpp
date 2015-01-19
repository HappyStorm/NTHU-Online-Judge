#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool isok(int, char**);

int main()
{
    char input[100010];
    while(gets(input)!=NULL){
        int ct=0;
        char* temp;
        char* sentence[100010];

        temp = strtok(input, " ");
        while(temp!=NULL){
            sentence[ct] = temp, ct++;
            temp = strtok(NULL, " ");
        }

        if(isok(ct, sentence))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

bool isok(int ct, char** sen)
{
    int num = ct/2;
    for(int i=0 ; i<num ; i++){
        if((strcmp(sen[i], sen[ct-i-1])!=0))
           return false;
    }
    return true;
}
