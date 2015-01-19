#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

char input[100000+10];
int main()
{
    memset(input, '\0', sizeof(input));
    while(gets(input)!=NULL){
        list<char> ans;
        ans.push_front('\0');
        list<char>::iterator point = ans.begin();
        int len = strlen(input), exist=0;
        for(int i=0 ; i<len ; i++){
            if(input[i]!='[' && input[i]!=']')
                ans.insert(point, input[i]);
            else if(input[i]=='[')
                point = ans.begin();
            else if(input[i]==']')
                point = ans.end(), point--;
        }
        point = ans.begin();
        char last[100000+10];
        memset(last, '\0', sizeof(last));
        for(int i=0 ; i<len ; i++)
            last[i] = *point, point++;
        printf("%s\n", last);
        memset(input, '\0', sizeof(input));
    }
    return 0;
}
