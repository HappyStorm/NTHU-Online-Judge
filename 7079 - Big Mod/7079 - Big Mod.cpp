#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    long long B, P, M;
    while(EOF!=scanf("%lld %lld %lld", &B, &P, &M)){
        int more[100000];
        int times=0;
        long long R=B%M;
        if(P%2==1 && P>1 && R!=0)
            more[times]=R, P--, times++;
        else if(P==0 && M!=1)
            R=1;
        else if(M==1)
            R=0, P=0;
        else if(R==0)
            P=0;

        while(P>1){
            if(R==1)
                break;
            while(R<M){
                if(P%2==0)
                    R*=R, P/=2;
                else
                    more[times]=R, R*=R, P = (P-1)/2, times++;
            }
            R = R%M;
       }
       for(int i=0 ; i<times ; i++)
            R = (R*(more[i]%M))%M;

       printf("%d\n", R);
    }
    return 0;
}
