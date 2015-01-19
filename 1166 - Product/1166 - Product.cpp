#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <list>
using namespace std;
char inputX[1000000+5], inputY[1000000+5];
int X[1000000+5], Y[1000000+5], ans[1000000+5];
int main()
{
    memset(inputX, '\0', sizeof(inputX)), memset(inputY, '\0', sizeof(inputY));
    memset(X, 0, sizeof(X)), memset(Y, 0, sizeof(Y));
    memset(ans, 0, sizeof(ans));
    while((gets(inputX)!=NULL) && (gets(inputY)!=NULL)){
        int lenX = strlen(inputX), lenY = strlen(inputY);
        for(int i=1000000, ct=lenX-1 ; ct>=0 ; --i, --ct)
            X[i] = inputX[ct]-'0';
        for(int i=1000000, ct=lenY-1 ; ct>=0 ; --i, --ct)
            Y[i] = inputY[ct]-'0';
        if(lenX>lenY){
            int anslen=1000000, shift=0, carry=0, temp=0, last=0;
            for(int i=1000000, cty=0 ; cty<lenY ; ++cty, --i){
                carry=0, temp=0;
                for(int j=1000000, ctx=0 ; ctx<lenX ; ++ctx, --j){
                    temp = ans[j-shift] + Y[i]*X[j] + carry;
                    carry = temp/10;
                    ans[j-shift] = temp%10;
                    last = j-shift;
                }
                 while(carry>0)
                    ans[last-1] = carry%10, carry/=10;
                ++shift;
            }
            if(carry>0)
                ans[last-1] = carry%10;
            int flag=0 , check=1;
            while(ans[flag]==0)
                ++flag;
            for(int i=flag ; i<=1000000 ; i++)
                printf("%d", ans[i]), check=0;
            if(check)
                printf("0");
            putchar(10);
        }
        else{
            int anslen=1000000, shift=0, carry=0, temp=0, last=0;
            for(int i=1000000, ctx=0 ; ctx<lenX ; ++ctx, --i){
                carry=0, temp=0;
                for(int j=1000000, cty=0 ; cty<lenY ; ++cty, --j){
                    temp = ans[j-shift] + X[i]*Y[j] + carry;
                    carry = temp/10;
                    ans[j-shift] = temp%10;
                    last = j-shift;
                }
                while(carry>0)
                    ans[last-1] = carry%10, carry/=10;
                ++shift;
            }
            if(carry>0)
                ans[last-1] = carry%10;
            int flag=0 , check=1;
            while(ans[flag]==0)
                ++flag;
            for(int i=flag ; i<=1000000 ; i++)
                printf("%d", ans[i]), check=0;
            if(check)
                printf("0");
            putchar(10);
        }
        memset(inputX, '\0', sizeof(inputX)), memset(inputY, '\0', sizeof(inputY));
        memset(X, 0, sizeof(X)), memset(Y, 0, sizeof(Y));
        memset(ans, 0, sizeof(ans));
    }
    return 0;
}
