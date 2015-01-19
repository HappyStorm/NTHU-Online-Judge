#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char input[100000];
int main()
{
    while(gets(input)!=NULL){
        int ct=0;
        char* temp;
        char* word[10000];

        temp = strtok(input, " ");
        while(temp!=NULL){
            int length = strlen(temp), mid_length = length/2;
            for(int i=0 ; i<mid_length ; i++){
                char t = temp[i];
                temp[i] = temp[length-i-1];
                temp[length-i-1] = t;
            }
            word[ct] = temp, ct++;
            temp = strtok(NULL, " ");
        }

        for(int i=0 ; i<ct ; i++){
            if(i!=ct-1)
                printf("%s ", word[i]);
            else
                printf("%s\n", word[i]);
        }
    }
    return 0;
}
