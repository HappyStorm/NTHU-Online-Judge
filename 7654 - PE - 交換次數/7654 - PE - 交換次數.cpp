#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void Mergesort(int, int[]);
void mymerge(int, int, int [], int [], int []);

int nums[1000000+10];
long long ans;
int main()
{
    int n;

    while(~scanf("%d", &n)){
        for(int i=0 ; i<n ; i++)
            nums[i]=0;
        for(int i=0 ; i<n ; i++)
            scanf("%d", &nums[i]);
        ans=0;
        Mergesort(n, nums);
        printf("%lld\n", ans);
    }
    return 0;
}


void Mergesort(int n, int num[])
{
    if(n==1)
        return;
    int Lhs = n/2, Rhs = n-Lhs;
    int left[Lhs], right[Rhs];

    for(int i=0 ; i<Lhs ; i++)
        left[i] = num[i];
    for(int i=0 ; i<Rhs ; i++)
        right[i] = num[Lhs+i];

    Mergesort(Lhs, left);
    Mergesort(Rhs, right);
    mymerge(Lhs, Rhs, left, right, num);
}
void mymerge(int L, int R, int left[], int right[], int num[])
{
    int l=0, r=0, index=0;
    while(l<L && r<R){
        if(right[r] >= left[l])
            num[index++] = left[l++];
        else
            num[index++] = right[r++], ans = ans+(L-l);
    }
    while(l<L)
        num[index++] = left[l++];
    while(r<R)
        num[index++] = right[r++];
}
