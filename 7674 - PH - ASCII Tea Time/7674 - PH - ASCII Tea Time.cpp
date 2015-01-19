#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
using namespace std;



int main()
{
    char input[100+10];
    memset(input, '\0', sizeof(input));
    while(gets(input)!=NULL){
        int len = strlen(input);
        if(len==0){
            putchar(10);
            memset(input, '\0', sizeof(input));
            continue;
        }
        char mirrow[100+10];
        memset(mirrow, '\0', sizeof(mirrow));
        int ct = len-1, check=0, first=0;
        while(input[first]==' ')
            first++;
        for(int i=0 ; i<len ; i++){
            if(input[i]!='*'){
                if(input[i]==' ')
                    check++;
                putchar(input[i]);
                mirrow[ct] = input[i], ct--;
            }
            else if(input[i]=='*'){
                putchar('*');
                if(check==len-1){
                    putchar(10);
                    break;
                }
                for(int j=ct+1 ; j<len-first ; j++)
                    putchar(mirrow[j]);
                putchar(10);
                break;
            }
        }
        memset(input, '\0', sizeof(input));
    }
    return 0;
}


