#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int row, col, flag=0;
    while(EOF!=scanf("%d %d", &row, &col)){
        getchar();
        if(row==0 && col==0)
            break;
        char origin[102][102]={{0}};
        int square[102][102]={{0}}, ans[102][102]={{0}};

        for(int i=1 ; i<=row ; i++)
            gets(origin[i]+1);
        for(int i=1 ; i<=row ; i++)
            for(int j=1 ; j<=col ; j++)
                if(origin[i][j]=='*')
                    square[i][j]=1;
                else
                    square[i][j]=0;
        for(int i=1 ; i<=row ; i++){
            for(int j=1 ; j<=col ; j++){
                for(int k=i-1 ; k<i+2 ; k++){
                    for(int m=j-1 ; m<j+2 ; m++){
                        if(k!=i || m!=j)
                            ans[i][j]+=square[k][m];
                    }
                }
            }
        }
        if(flag!=0)
            printf("\n");
        printf("Field #%d:\n", ++flag);
        for(int i=1 ; i<=row ; i++){
            for(int j=1 ; j<=col ; j++){
                if(origin[i][j]=='*')
                    printf("*");
                else
                    if(ans[i][j]!=0)
                        printf("%d", ans[i][j]);
                    else
                        printf("0");
            }
            printf("\n");
        }
    }
    return 0;
}
