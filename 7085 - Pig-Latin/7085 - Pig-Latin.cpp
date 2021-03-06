#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool is_parent(char);

char input[3000000];

int main()
{
    while(gets(input)!=NULL){
        int length = strlen(input);
        for(int i=0 ; i<length ; i++){
            char temp[10000]={0};
            if(isalpha(input[i])){
                for(int j=0 ; isalpha(input[i]) ; j++, i++)
                    temp[j] = input[i];
                if(is_parent(temp[0]))
                   printf("%say", temp);
                else{
                    char* newtemp = temp+1;
                    printf("%s%cay", newtemp, temp[0]);
                }
                i--;
            }
            else
                putchar(input[i]);
        }
        printf("\n");
    }
    return 0;
}

bool is_parent(char sentence)
{
    char parent[] = "aeiouAEIOU";
    for(int i=0; i<10 ; i++)
        if(sentence==parent[i])
            return true;
    return false;
}
