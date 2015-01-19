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

long long cal(long long, int);
int Len(long long);
int main()
{
    int flag=0;
    char input[60];
    long long num[14];
    while(gets(input)!=NULL){
        // For child
        memset(num, 0, sizeof(num));
        int lenc = strlen(input)/4;
        for(int i=1 ; i<=3 ; i++){
            memset(input, '\0', sizeof(input));
            gets(input);
            int len = strlen(input);
            for(int j=0 ; j<len ; j++){
                if(j%4!=0){
                    if(input[j]=='*')
                        num[j/4]++;
                }
            }
        }
        long long child=0;
        for(int i=0 ; i<lenc ; i++)
            child+=(cal(num[i], lenc-i-1));

        // Middle process
        gets(input);
        memset(input, '\0', sizeof(input));
        gets(input);

        // For parent
        memset(num, 0, sizeof(num));
        int lenp = strlen(input)/4;
        for(int i=1 ; i<=3 ; i++){
            memset(input, '\0', sizeof(input));
            gets(input);
            int len = strlen(input);
            for(int j=0 ; j<len ; j++){
                if(j%4!=0){
                    if(input[j]=='*')
                        num[j/4]++;
                }
            }
        }
        long long parent=0;
        for(int i=0 ; i<lenp ; i++)
            parent+=(cal(num[i], lenp-i-1));
        gets(input);

        long long gcd = __gcd(child, parent);
        //printf("Child= %lld  Parent= %lld  GCD= %lld\n", child, parent, gcd);
        int lena = Len(gcd);
        memset(num, -1, sizeof(num));

        for(int i=0 ; i<lena ; i++)
            num[lena-i-1] = gcd%10, gcd/=10;

        //for(int i=0 ; i<lena ; i++)
        //    printf("%d ", num[i]);
        if(flag!=0)
            putchar(10);
        flag++;
        for(int i=0 ; i<5 ; i++){
            for(int j=0 ; j<lena*4+1 ; j++){
                if(i%4==0){
                    if(j%4!=0)putchar('-');
                    else putchar('+');
                }
                else{
                    if(j%4==0)
                        putchar('|');
                    else{
                        if(num[j/4]!=-1 && num[j/4]>0)
                            putchar('*'), num[j/4]--;
                        else
                            putchar(' ');
                    }
                }
            }
            putchar(10);
        }
    }
    return 0;
}

long long cal(long long num, int time)
{
    long long ans=1;
    for(int i=0 ; i<time ; i++)
        ans*=10;
    return num*ans;
}

int Len(long long n)
{
    int time=1;
    while(n/10>0)
        time++, n/=10;
    return time;
}
