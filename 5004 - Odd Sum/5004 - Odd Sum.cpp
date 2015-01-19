#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int num;
    scanf("%d ", &num);

    for(int i=0 ; i<num ; i++){
        int low, up, sum=0;
        scanf("%d %d", &low, &up);
        for(int j=low ; j<=up ; j++){
            if(j%2==1)
                sum+=j;
        }
        printf("Case %d: %d\n", i+1, sum);
    }
    return 0;
}
