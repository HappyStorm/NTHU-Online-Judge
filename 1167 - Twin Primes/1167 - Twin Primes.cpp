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
int S, prime_num;
struct twin{
    int left, right;
};
bool prime[20000000+5];
int primeNum[2000000];
vector<twin> ans;
twin temp;

void primetable()
{
    memset(prime, true, sizeof(prime));
    memset(primeNum, 0, sizeof(primeNum));
    prime_num=0;
    prime[0] = false, prime[1] = false;
    for(int i=2 ; i<=20000000 ; i++){
        if(prime[i]){
            primeNum[prime_num++] = i;
            for(int j=i ; j<=20000000 ; j+=i)
                prime[j] = false;
        }
    }
}
int main()
{
    primetable();
    int p=0, left, right;
    for(int i=1 ; i<=100000 ; i++){
        for(int j=p ; j<prime_num ; j++){
            left = primeNum[j], right = primeNum[j+1];
            if((right-left)==2)
                temp.left = primeNum[j], temp.right = primeNum[j+1], p=j+1, ans.push_back(temp);
        }
    }
    while(~scanf("%d", &S))
        printf("(%d, %d)\n", ans[S-1].left, ans[S-1].right);
    return 0;
}
