#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int gcd(int, int);

int main()
{
    int num;
    while(~scanf("%d", &num)){
        if(num==0)
            break;
        int N[50+10]={0};
        for(int i=0 ; i<num ; i++)
            scanf("%d", &N[i]);

        int part=0, allpair=0;
        for(int i=0 ; i<num ; i++){
            for(int j=i+1 ; j<num ; j++){
                allpair++;
                if(gcd(N[i], N[j])==1)
                    part++; //printf("All pair= (%d,%d)\n", N[i], N[j]);
            }
        }

        double pi = sqrt((double)6*allpair/((double)part));
        if(part!=0)
            printf("%.6f\n", pi);
        else
            printf("No estimate for this data set.\n");
    }
    return 0;
}

int gcd(int a, int b)
{
    int ans=0;
    while(max(a,b)%min(a,b)!=0){
        if(a>b)
            a = a%b, ans=a;
        else if(a<b)
            b = b%a, ans=b;
        else
            ans = a;
    }
    return min(a,b);
}
