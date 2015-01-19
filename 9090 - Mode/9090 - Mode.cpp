#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int num;
    while(~scanf("%d", &num)){
        if(num==0)
            break;
        int frequency[1000+10]={0};
        for(int i=0 ; i<num ; i++){
            int temp;
            scanf("%d", &temp);
            frequency[temp]++;
        }
        int ans=0, flag=0;
        for(int i=0 ; i<=1000 ; i++){
            if(frequency[i]>ans)
                ans = frequency[i], flag=i;
        }
        printf("%d\n", flag);
    }
    return 0;
}
