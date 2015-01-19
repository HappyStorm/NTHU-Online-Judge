#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);

    for(int i=0 ; i<test ; i++){
        int amp, fre;
        scanf("%d %d", &amp, &fre);

        for(int j=0 ; j<fre ; j++){

            for(int k=1 ; k<=amp ; k++){
                for(int m=0 ; m<k ; m++){
                    printf("%d", k);
                }
                printf("\n");
            }
            for(int k=amp-1 ; k>0 ; k--){
                for(int m=0 ; m<k ; m++){
                    printf("%d", k);
                }
                printf("\n");
            }
            if(i!=test-1 || j!=fre-1)
                printf("\n");
        }
    }
    return 0;
}
