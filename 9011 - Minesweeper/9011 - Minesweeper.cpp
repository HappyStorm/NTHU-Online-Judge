#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int side, flag=0;
    while(EOF!=scanf("%d", &side)){
        int square[102][102]={}, ans[102][102]={};

        for(int i=1 ; i<=side ; i++)
            for(int j=1 ; j<=side ; j++)
                scanf("%d", &square[i][j]);

        //printf("1. OK\n");

        /*for(int i=1 ; i<=side ; i++){
            for(int j=1 ; j<=side ; j++)
                printf("%d ", square[i][j]);
                printf("\n");
        }*/
        for(int i=1 ; i<=side ; i++){
            for(int j=1 ; j<=side ; j++){
                //printf("j. OK\n");
                for(int k=i-1 ; k<i+2 ; k++){
                    //printf("k. OK\n");
                    for(int m=j-1 ; m<j+2 ; m++){
                        //printf("m. OK\n");
                        if(k!=i || m!=j)
                            ans[i][j]+=square[k][m];
                    }
                }
            }
        }
        //printf(". OK\n");
        /*if(flag==0)
            flag=1;
        else
            printf("\n");*/

        for(int i=1 ; i<=side ; i++){
            for(int j=1 ; j<=side ; j++){
                if(j!=side)
                    printf("%d ", ans[i][j]);
                else
                    printf("%d", ans[i][j]);

            }
            printf("\n");
        }
    }
    return 0;
}
