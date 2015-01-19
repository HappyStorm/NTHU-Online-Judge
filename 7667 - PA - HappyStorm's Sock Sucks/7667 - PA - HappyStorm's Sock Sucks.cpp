#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


int socks[17600][5];
int number(char[]);
int kind(char[]);
char* whatsize(int);
int main()
{
    int test, times=1;
    scanf("%d", &test);
    while(test--){
        printf("Case #%d\n", times++);
        memset(socks, 0, sizeof(socks));
        int n;
        scanf("%d", &n), getchar();
        char name[5], si[3];
        memset(name, '\0', sizeof(name)), memset(si, '\0', sizeof(si));
        for(int i=0 ; i<n ; i++){
            scanf("%s %s", name, si), socks[number(name)][kind(si)]++;
            memset(name, '\0', sizeof(name)), memset(si, '\0', sizeof(si));
        }
        int check=0;
        for(int i=0 ; i<17600 ; i++){
            for(int j=0 ; j<5 ; j++)
                if(socks[i][j]%2==1)
                    printf("%c%c%c %s\n", (i/676)+'a', ((i/26)%26)+'a', (i%26)+'a', whatsize(j)), check++;
        }
        if(!check)
            puts("Socks fine");
    }
    return 0;
}

int number(char *name)
{
    return (name[0]-'a')*26*26 + (name[1]-'a')*26 + (name[2]-'a');
}
int kind(char *si)
{
    if(si[0]=='S')                      return 0;
    else if(si[0]=='M')                 return 1;
    else if(si[0]=='L')                 return 2;
    else if(si[0]=='X' && si[1]=='L')   return 4;
    else                                return 3;
}
char* whatsize(int x)
{
    char *ans = (char*) malloc(3*sizeof(char));
    memset(ans, '\0', sizeof(ans));
    if(x==0)        memcpy(ans, "S", 1);
    else if(x==1)   memcpy(ans, "M", 1);
    else if(x==2)   memcpy(ans, "L", 1);
    else if(x==3)   memcpy(ans, "X", 1);
    else            memcpy(ans, "XL", 2);
    return ans;
}
