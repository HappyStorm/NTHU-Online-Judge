#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool mycompare(int, int);
int N, M;
int main()
{
    int nums[10001];
    while(EOF!=scanf("%d%d", &N, &M)){
        if(N==0 && M==0)
            break;
        for(int i=0 ; i<N ; i++)
            scanf("%d", &nums[i]);
        sort(nums, nums+N, mycompare);
        printf("%d %d\n", N, M);
        for(int i=0 ; i<N ; i++)
            printf("%d\n", nums[i]);
    }
    printf("0 0\n");
    return 0;
}

bool mycompare(int a, int b)
{
    int aOdd = abs(a%2), bOdd = abs(b%2);
    if(a%M!=b%M)
        return a%M < b%M;
    else if(aOdd!=bOdd)
        return aOdd > bOdd;
    else if(aOdd)
        return a > b;
    else
        return a < b;
}
