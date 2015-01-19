#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

char input[1000001];
char output[1000001];

int main()
{
    while(gets(input)!=NULL){
        int ct=0;
        while(input[ct]!=NULL)
            output[ct] = input[ct], ct++;
        for(int i=ct-1 ; i>=0 ; i--)
            putchar(output[i]);
        putchar('\n');
    }
    return 0;
}
