#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);

    while(test--){
        int people;
        scanf("%d", &people);

        double grades[1005];
        for(int i=0 ; i<people ; i++){
            scanf("%lf", &grades[i]);
        }

        double total=0.0;
        for(int i=0 ; i<people ; i++)
            total+=grades[i];

        double average = total/people;

        double pass=0.0;
        for(int i=0 ; i<people ; i++){
            if(grades[i]>average)
                pass++;
        }

        double pass_rate = pass/people*100;
        printf("%.3lf%%\n", pass_rate);
    }
    return 0;
}
