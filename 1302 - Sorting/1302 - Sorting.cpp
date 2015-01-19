#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int n, temp;
        vector<int> num;
        scanf("%d", &n);
        for(int i=0 ; i<n ; i++){
            scanf("%d", &temp);
            num.push_back(temp);
        }
        sort(num.begin(), num.end());
        for(int i=0 ; i<n ; i++)
            if(i==n-1)
                printf("%d\n", num[i]);
            else
                printf("%d ", num[i]);
    }
    return 0;
}
