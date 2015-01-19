#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

long long A[500+10][500+10];
long long B[500+10][500+10];
long long C[500+10][500+10];
int main()
{
    long long m, n, p;
    while(~scanf("%lld %lld %lld", &m, &n, &p)){
        memset(A, 0, sizeof(A)), memset(B, 0, sizeof(B)), memset(C, 0, sizeof(C));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                scanf("%lld", &A[i][j]);
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<p ; j++){
                scanf("%lld", &B[i][j]);
            }
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<p ; j++){
                for(int k=0 ; k<n ; k++){
                    C[i][j]+=(A[i][k]*B[k][j]);
                }
            }
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<p ; j++){
                if(j==p-1)
                    printf("%lld\n", C[i][j]);
                else
                    printf("%lld ", C[i][j]);
            }
        }
    }
    return 0;
}
