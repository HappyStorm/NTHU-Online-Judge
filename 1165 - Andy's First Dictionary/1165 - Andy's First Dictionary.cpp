#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <list>
using namespace std;
char input[200+10];
set<string> dic;

int main()
{
    dic.clear();
    memset(input, '\0', sizeof(input));
    while(gets(input)!=NULL){
        int len = strlen(input);
        if(len==0) continue;
        int start=0, over=0, ct=0;
        char word[6000];
        memset(word, '\0', sizeof(word));
        for(int i=0 ; i<len ; i++){
            if(isalpha(input[i]) && start==0)
                word[ct] = tolower(input[i]), ++ct, start=1;
            else if(isalpha(input[i]) && start==1)
                word[ct] = tolower(input[i]), ++ct;
            else if(!isalpha(input[i]) && start==1)
                dic.insert((string) word), memset(word, '\0', sizeof(word)), ct=0, start=0;
        }
        int wlen = strlen(word);
        if(wlen!=0)
             dic.insert((string) word);
        memset(word, '\0', sizeof(word));
        memset(input, '\0', sizeof(input));
    }
    set<string>::iterator iter = dic.begin();
    for( ; iter!= dic.end(); iter++)
        puts((*iter).c_str());
    return 0;
}
