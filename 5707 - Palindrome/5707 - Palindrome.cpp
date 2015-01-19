#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;

char input[100000+10];

int main()
{
    memset(input, '\0', sizeof(input));
    while(gets(input)!=NULL){
        int check=1, len = strlen(input);
        for(int i=0 ; i<len/2 ; i++)
            if(input[i]!=input[len-i-1]){
                check=0; break;}
        if(check)
            puts("Yes");
        else
            puts("No");
        memset(input, '\0', sizeof(input));
    }
    return 0;
}
