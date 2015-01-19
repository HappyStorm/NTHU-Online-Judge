#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;


int main()
{
    int n, q;
    while(~scanf("%d %d", &n, &q)){
        map<int, int> number;
        map<int, int>::iterator iter;
        int temp;
        for(int i=0 ; i<n ; i++){
            scanf("%d", &temp);
            iter = number.find(temp);
            if(iter==number.end())
                number[temp] = 1;
            else
                (iter->second)++;
        }
        int query;
        for(int i=0 ; i<q ; i++){
            scanf("%d", &query);
            iter = number.find(query);
            if(iter==number.end())
                printf("0\n");
            else
                printf("%d\n", (iter->second));
        }
    }
    return 0;
}
