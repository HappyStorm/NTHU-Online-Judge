#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;


int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int m, n, p;
        int A[100+5][100+5]={{0}}, B[100+5][100+5]={{0}}, C[100+5][100+5]={{0}};
        scanf("%d %d %d", &m, &n, &p);
        for(int i=0 ; i<m ; i++)
            for(int j=0 ; j<n ; j++)
                scanf("%d", &A[i][j]);
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<p ; j++)
                scanf("%d", &B[i][j]);
        for(int i=0 ; i<m ; i++)
            for(int j=0 ; j<p ; j++)
                for(int k=0 ; k<n ; k++)
                    C[i][j]+=A[i][k]*B[k][j];
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<p ; j++)
                if(j!=p-1)
                    printf("%d ", C[i][j]);
                else
                    printf("%d\n", C[i][j]);
        }
        putchar(10);
    }
    return 0;
}
