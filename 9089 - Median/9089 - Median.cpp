#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    while(EOF!=scanf("%d", &num)){
        if(num==0)
            break;
        vector<long long> nums;
        for(int i=0 ; i<num ; i++){
            long long temp;
            scanf("%lld", &temp);
            nums.push_back(temp);
        }
        sort(nums.begin(), nums.end());
        if(num%2==1)
            printf("%lld.0\n", nums.at((num-1)/2));
        else{
            if((nums.at(num/2)+nums.at(num/2-1))%2==0)
                printf("%lld.0\n", (nums.at(num/2)+nums.at(num/2-1))/2);
            else
                printf("%lld.5\n", (nums.at(num/2)+nums.at(num/2-1))/2);
        }
    }
    return 0;
}
