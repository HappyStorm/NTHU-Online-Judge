#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int m, n, ans=0, flag=0;
        scanf("%d %d", &m, &n), getchar();
        char oneline[5000]={0};
        for(int i=0 ; i<m*4+1; i++){
            gets(oneline);
            for(int j=0 ; j<n*4+1 ; j++){
                if(oneline[j]=='*' && flag==0)
                    flag++;
                else if(oneline[j]=='*' && flag==1)
                    flag++;
                else if(oneline[j]=='*' && flag==2)
                    ans++, flag=0;
                else if(oneline[j]!='*' && flag==2)
                    flag=0;
                else
                    flag=0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
