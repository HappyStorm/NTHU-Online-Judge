#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int f1=0, f2=1, m, ans=1;
        scanf("%d", &m);
        for(int i=1 ; i<m ; i++){
            ans = f1 + f2;
            f1 = f2, f2 = ans;
        }
        printf("第%d分鐘 圍觀人數%d人\n", m, ans);
    }
    return 0;
}
