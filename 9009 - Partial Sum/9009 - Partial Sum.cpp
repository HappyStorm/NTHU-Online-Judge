#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int nums;
        scanf("%d", &nums);
        vector<int> numarray;
        for(int i=0 ; i<nums ; i++){
            int temp;
            scanf("%d", &temp), numarray.push_back(temp);
        }
        int numquery;
        scanf("%d", &numquery);
        for(int i=0 ; i<numquery ; i++){
            int low, high, ans=0;
            scanf("%d %d", &low, &high);
            for(int j=low-1 ; j<high ; j++)
                ans+=numarray.at(j);
            printf("%d\n", ans);
        }
    }
    return 0;
}
