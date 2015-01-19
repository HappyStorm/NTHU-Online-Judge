#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int N;
char in[100+5];
vector<string> num;

bool cmp(string a, string b)
{
    if(a[0]!='-' && b[0]!='-'){
        if(a.size()==b.size())
            return a<b;
        else
            return a.size()<b.size();
    }
    else if(a[0]=='-' && b[0]=='-'){
        if(a.size()==b.size())
            return a>b;
        else
            return a.size()>b.size();
    }
    else if(a[0]=='-' && b[0]!='-')
        return a<b;
    else if(a[0]!='-' && b[0]=='-')
        return a<b;
}
int main()
{
    int times=0;
    while(~scanf("%d", &N)){
        num.clear();
        getchar();
        for(int i=0 ; i<N ; i++){
            memset(in, '\0', sizeof(in));
            gets(in);
            num.push_back((string) in);
        }
        sort(num.begin(), num.end(), cmp);

        if(times++) putchar(10);
        for(int i=0 ; i<num.size() ; i++)
            printf("%s\n", num[i].c_str());
    }
    return 0;
}
