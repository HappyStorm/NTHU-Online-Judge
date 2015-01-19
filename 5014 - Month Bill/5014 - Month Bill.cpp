#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

long long mypow(long long, long long);
int main()
{
    char input[10000]={0}, ct=1;
    while(gets(input)!=NULL){
        long long num[5]={0};
        int length = strlen(input), isnum=0, first=-1, last=0, flag=0, isnegative=0;
        for(int i=0 ; i<length ; i++){
            if(input[i]<='9' && '0'<=input[i] && i!=length-1 && first==-1)
                first=i, isnum=1;
            else if(input[i]=='-')
                isnegative=1;
            else if(input[i]==' ' && isnum==1 && i!=length-1){
                last=i-1, isnum=0;
                for(int j=first ; j<=last ; j++)
                    num[flag] += (int)(input[j]-'0')*mypow(10, last-j);
                if(isnegative)
                    num[flag]*=-1;
                first=-1, last=0, flag++, isnegative=0;
            }
            else if(i==length-1 && isnum==1){
                last=i, isnum=0;
                for(int j=first ; j<=last ; j++)
                    num[flag] += (int)(input[j]-'0')*mypow(10, last-j);
                if(isnegative)
                    num[flag]*=-1;
                first=-1, last=0, flag++;
            }
            else if(input[i]<='9' && '0'<=input[i] && i==length-1 && isnum==0){
                num[flag] += (int)(input[i]-'0');
                if(isnegative)
                    num[flag]*=-1;
                first=-1, last=0, flag++, isnegative=0;
            }
        }
        long long ans=0;
        for(int i=0 ; i<flag ; i++)
            ans+=num[i];
        printf("Day %d: %lld\n", ct++, ans);
    }
    return 0;
}

long long mypow(long long a, long long b)
{
    long long ans=1;
    for(int i=0 ; i<b ; i++)
        ans*=a;
    return ans;
}
