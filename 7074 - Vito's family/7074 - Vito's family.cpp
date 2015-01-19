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
        int people, temp;
        vector<int> door;
        scanf("%d", &people);

        for(int i=0 ; i<people; i++){
           scanf("%d", &temp);
           door.push_back(temp);
        }
        sort(door.begin(), door.end());
        //printf("People: %d\n", people);
        int mid;
        if(people%2==1)
            mid = door.at((people-1)/2);
        else
            mid = (door.at(people/2)+door.at(people/2-1))/2;

        //printf("Mid= %d\n", mid);

        int sum=0;
        for(int i=0 ; i<people ; i++)
            sum = sum + abs(mid-door.at(i));

        printf("%d\n", sum);
    }
    return 0;
}
