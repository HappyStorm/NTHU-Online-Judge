#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
using namespace std;

struct card{
    int prefix;
};
struct student{
    int k, sum;
};
void Mergesort(int, student*);
void mymerge(int, int, student*, student*, student*);
student students[1000000+10];
int main()
{
    int N, Q, K;
    while(~scanf("%d %d %d", &N, &Q, &K)){
        vector<card> allcard;
        card c;
        int temp, sum=0;
        for(int i=0 ; i<N ; i++)
            scanf("%d", &temp), sum+=temp, c.prefix = sum, allcard.push_back(c);
        int A, B, tempsum=0;
        student s;
        for(int i=0 ; i<Q ; i++){
            scanf("%d %d", &A, &B), A-=1, B-=1;
            if(A==0)
                tempsum = allcard[B].prefix;
            else
                tempsum = allcard[B].prefix-allcard[A-1].prefix;
            s.sum = tempsum, s.k=0, students[i] = s;
        }
        Mergesort(Q, students);
        int aplus=0;
        for(int i=0 ; i<Q ; i++)
            if(students[i].k>=K)
                aplus++;
        printf("%d\n", aplus);
    }
    return 0;
}
void Mergesort(int n, student *allstudent)
{
    if(n==1)
        return;
    int Lhs = n/2, Rhs = n-Lhs;
    student *left = (student*) malloc(Lhs*sizeof(student));
    student *right = (student*) malloc(Rhs*sizeof(student));
    //student left[Lhs], right[Rhs];
    for(int i=0 ; i<Lhs ; i++)
        left[i] = allstudent[i];
    for(int i=0 ; i<Rhs ; i++)
        right[i] = allstudent[Lhs+i];
    Mergesort(Lhs, left);
    Mergesort(Rhs, right);
    mymerge(Lhs, Rhs, left, right, allstudent);
    free(left), free(right);
}
void mymerge(int L, int R, student *left, student *right, student *allstudent)
{
    int l=0, r=0, index=0;
    while(l<L && r<R){
        if(right[r].sum >= left[l].sum)
            allstudent[index++] = right[r++];
        else
            left[l].k += (R-r), allstudent[index++] = left[l++];
    }
    while(l<L)
        allstudent[index++] = left[l++];
    while(r<R)
        allstudent[index++] = right[r++];
}
