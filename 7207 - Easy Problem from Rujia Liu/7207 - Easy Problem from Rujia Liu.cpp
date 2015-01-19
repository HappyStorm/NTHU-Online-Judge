#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    vector<int> nums;
    while(EOF!=scanf("%d %d", &n, &m)){
        for(int i=0 ; i<n ; i++){
            int temp;
            scanf("%d", &temp);
            nums.push_back(temp);
        }
        while(m--){
            int k, v, ans=0;
            scanf("%d %d", &k, &v);
            for(int i=0 ; i<n ; i++){
                if(nums.at(i)==v)
                    k--;
                if(k==0){
                    ans = i+1;
                    break;
                }
            }
            if(k>0)
                printf("0\n");
            else
                printf("%d\n", ans);
        }
    }
    return 0;
}
