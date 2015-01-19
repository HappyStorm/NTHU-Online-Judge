#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;
char word[2000];
int main()
{
    while(gets(word)!=NULL){
        int times=0, length=strlen(word), isstart=0;
        for(int i=0 ; i<length ; i++){
            if(i==0 && 'A'<=word[i] && word[i]<='Z' && isstart==0)
                isstart=1;
            if(i!=0 && !isalpha(word[i-1]) && 'A'<=word[i] && word[i]<='Z' && isstart==0)
                isstart=1;
            if(!isalpha(word[i]) && isstart==1){
                times++;
                isstart=0;
            }
            if(i==length-1 && isstart==1)
                times++;
        }
        printf("%d\n", times);
    }
    return 0;
}
