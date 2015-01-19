#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);

    while(test--){
        int L, num_ant, shortest=0, longest=0, temp;
        scanf("%d %d", &L, &num_ant);

        vector<int> ants;
        for(int i=0 ; i<num_ant ; i++){
            scanf("%d", &temp);
            ants.push_back(temp);
        }
        sort(ants.begin(), ants.end());

        int mid_L;
        if(L%2!=0)
            mid_L = (L+1)/2;
        else
            mid_L = L/2;

        vector<int> length;
        for(int i=0 ; i<num_ant ; i++)
            length.push_back(abs(mid_L-ants.at(i)));
        sort(length.begin(), length.end());


        int close = length.front();
        for(int i=0 ; i<num_ant ; i++){
            if(abs(mid_L-ants.at(i))==close){
                if((L-ants.at(i)>ants.at(i))){
                    if(ants.at(i)>shortest)
                        shortest = ants.at(i);
                }
                else
                    if(L-ants.at(i)>shortest)
                        shortest = L-ants.at(i);
            }
        }

        int leftside = L-ants.front();
        int rightside = ants.back();
        if(leftside>rightside)
            longest = leftside;
        else
            longest = rightside;

        printf("%d %d\n", shortest, longest);
    }
    return 0;
}
