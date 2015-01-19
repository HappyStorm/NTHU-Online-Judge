#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int side;
    while(~scanf("%d", &side)){
        int sum=0;
        if(side==0)
            break;
        else{

            for(int i=0 ; i<=side ; i++){
                sum = sum + i*i;
            }

        }
        cout << sum << endl;
    }
    return 0;
}
