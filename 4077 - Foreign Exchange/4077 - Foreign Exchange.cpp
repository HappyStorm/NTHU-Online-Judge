#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int people;
    while(EOF!=scanf("%d", &people)){
        if(people==0)
            break;
        int flag=1;
        vector<int> start;
        vector<int> target;

        for(int i=0 ; i<people ; i++){
            int temp1, temp2;
            scanf("%d %d", &temp1, &temp2);
            start.push_back(temp1), target.push_back(temp2);
        }
        sort(start.begin(), start.end()), sort(target.begin(), target.end());
        for(int i=0 ; i<people ; i++)
            if(start.at(i)!=target.at(i)){
                flag=0;
                break;
            }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
