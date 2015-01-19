#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <cmath>
#include <cctype>
#include <cstring>
#include <algorithm>
#define M 100000007
using namespace std;
int n;
long long tree[1000+5];


int main()
{
    tree[0] = 1, tree[1] = 1, tree[2] = 2, tree[3] = 5;
    for(int i=4 ; i<=1000 ; i++)
        for(int j=0 ; j<i ; j++)
            tree[i] += (tree[j] * tree[i-j-1]) % M, tree[i] = tree[i] % M;
    while(~scanf("%d", &n))
        printf("%d\n", tree[n]);
    return 0;
}
