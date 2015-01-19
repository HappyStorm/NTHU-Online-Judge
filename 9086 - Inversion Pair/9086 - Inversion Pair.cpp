#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void Mergesort(int, int*);
void my_merge(int, int, int*, int*, int*);
int nums[10000010]={0};
long long ans=0;
int main()
{
    int n;
    while(EOF!=scanf("%d", &n)){
        if(n==0)
            break;
        for(int i=0 ; i<n ; i++)
            scanf("%d", &nums[i]);
        ans=0;
        Mergesort(n, nums);
        printf("%lld\n", ans);
    }
    return 0;
}

void Mergesort(int num, int* data)
{
    if(num==1)
        return;
    int Lhs = num/2;
    int Rhs = num-Lhs;
    int left[Lhs], right[Rhs];

    //Copy data to local array.(to left[] and right[])
    for(int i=0 ; i<Lhs ; i++)
        left[i] = data[i];
    for(int i=0 ; i<Rhs ; i++)
        right[i] = data[i+Lhs];
    //After copy, then cut the array until the length of array = 1.
    Mergesort(Lhs, left), Mergesort(Rhs, right);
    //Then, start to merge the arrays.
    my_merge(Lhs, Rhs, left, right, data);
}
void my_merge(int L_max, int R_max, int* left, int* right, int* data)
{
    int index=0, l=0, r=0;
    //While these two arrays are not out of its bound.
    while(l<L_max && r<R_max){
        if(left[l]<=right[r])
            data[index++] = left[l++];
        else
            data[index++] = right[r++], ans+=(L_max-l);
    }
    while(l<L_max)
        data[index++] = left[l++];
    while(r<R_max)
        data[index++] = right[r++];
}
