#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct State{
  int B, W;
};

int  white[1000+10][1000+10], black[1000+10][1000+10];
State chess[1000+10][1000+10];
int main()
{
    int m, n, Q, flag=1;
    while(~scanf("%d %d %d", &m, &n, &Q)){
        if(m==0 && n==0 && Q==0)
            break;
        getchar();
        memset(white, 0, sizeof(white)), memset(black, 0, sizeof(black));
        for(int i=0 ; i<=m+1 ; i++)
            for(int j=0 ; j<=n+1 ; j++)
                chess[i][j].B=0, chess[i][j].W=0;
        long long Breadline=0, Wcake=0;
        char input[1000+10];
        for(int i=1 ; i<=m ; i++){
            gets(input);
            for(int j=1, k=0 ; k<n ; j++, k++){
                if(input[k]=='B')
                    black[i][j]=1;
                else if(input[k]=='W')
                    white[i][j]=1;
                chess[i][j].B+=black[i][j], chess[i][j].W+=white[i][j];
                chess[i][j].B+=(chess[i-1][j].B + chess[i][j-1].B - chess[i-1][j-1].B);
                chess[i][j].W+=(chess[i-1][j].W + chess[i][j-1].W - chess[i-1][j-1].W);
            }
        }
        int x1, y1, x2, y2, tempB=0, tempW=0, BX, LX, BY, LY;
        for(int i=0 ; i<Q ; i++){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            BX = max(x1, x2), BY = max(y1, y2), LX = min(x1, x2), LY = min(y1, y2);
            tempB = chess[BX][BY].B - chess[BX][LY-1].B - chess[LX-1][BY].B + chess[LX-1][LY-1].B;
            tempW = chess[BX][BY].W - chess[BX][LY-1].W - chess[LX-1][BY].W + chess[LX-1][LY-1].W;
            Breadline+=tempB, Wcake+=tempW;
        }
        printf("Case #%d:\n", flag++);
        printf("Redline: %lldpts Cake: %lldpts\n", Breadline, Wcake);
        if(Breadline>Wcake)
            printf("Redline wins!\n");
        else if(Breadline<Wcake)
            printf("Cake wins!\n");
        else
            printf("Tie!\n");
    }
    return 0;
}
