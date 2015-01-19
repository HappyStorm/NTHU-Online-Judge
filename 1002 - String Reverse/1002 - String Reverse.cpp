#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

char input[1000001];
char output[1000001];

int main()
{
    while(EOF!=scanf("%[a-z ]", input)){
        int i=0;
        while(input[i]!=NULL){
            output[i] = input[i];
            i++;
        }
        for(int j=i-1 ; j>=0 ; j--)
            cout << output[j];
        cout << '\n';
    }

    return 0;
}
