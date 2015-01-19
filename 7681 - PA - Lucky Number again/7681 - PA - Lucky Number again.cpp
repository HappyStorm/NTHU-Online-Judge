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
int N, ans, len;
vector<long long> all;
void lucky(long long);
int legal(long long);
int main()
{
    lucky(0);
    sort(all.begin(), all.end());
    //printf("All.size()= %d\n", all.size());
    //for(int i=0 ; i<all.size() ; i++)
    //    printf("All[%d]= %lld\n", i, all[i]);

    while(~scanf("%d", &N)){
        ans = 0;
        for(int i=0 ; i<all.size() ; i++)
            if(all[i]<=N)
                ans++;
            else
                break;
        printf("%d\n", ans);
        //printf("All[0]= %lld\n", all.at(1));
    }
    return 0;
}

void lucky(long long cur)
{
    if(cur>1000000000)
        return;
    int flag=0;
    for(int i=0 ; i<=9 ; ++i){
        if(cur==0 && i==0) continue;
        flag = legal(cur*10+i);
        if(flag<=2 && (cur*10+i)<=1000000000)
            all.push_back(cur*10+i);
        if(flag<=2)
            lucky(cur*10+i);
    }
}

int legal(long long num)
{
    //printf("Number= %lld\n", num);
    if(num<10)
        return 1;
    int appear=1, first = num%10, second=-1, temp;
    while(num>0){ // num= 110, first=0, second=1,
        temp = num%10;
        if(temp!=first && second==-1)
            second = temp, appear--;
        else if(temp!=first && temp!=second && second!=-1)
            return 5;
        num/=10;
    }
    if(!appear)
        return 2;
    else if(appear==1)
        return 1;
    else
        return 5;
}
