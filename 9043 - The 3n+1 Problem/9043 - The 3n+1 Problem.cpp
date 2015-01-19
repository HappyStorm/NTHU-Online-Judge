#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int dp[1000001]={0};
int calculate(int);
int base(unsigned long long);
int main()
{
    int input;
    while(EOF!=scanf("%d", &input))
        printf("%d\n", calculate(input));
    return 0;
}

int calculate(int num)
{
    if(num==1 || num>1000000)
        return base(num);
    else if(dp[num])
        return dp[num];
    else
        if(num%2==0)
            return dp[num] = calculate(num/2)+1;
        else
            return dp[num] = calculate(3*num+1)+1;
}

int base(unsigned long long num)
{
    int ct=0;
    while(num!=1){
        if(num%2==1)
            num=3*num+1;
        else
            num/=2;
        ct++;
    }
    return ct;
}
