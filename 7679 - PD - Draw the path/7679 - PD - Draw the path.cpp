#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;
int N, L, connect[2000+5][2000+5], point[2000+5][2000+5], change[2000+5];

int main()
{
    int times=1;
    while(~scanf("%d %d", &N, &L)){
        memset(connect, 0, sizeof(connect));
        memset(point, 0, sizeof(point));
        memset(change, 0, sizeof(change));
        for(int i=0 ; i<N ; i++){
            connect[i][0] = 0, connect[i][L-1] = 0;
            point[i][0] = 0, point[i][L-1] = 0;
        }
        int th, row;
        for(int i=0 ; i<N ; i++){
            scanf("%d", &change[2*i]);
            for(int j=0 ; j<change[2*i] ; j++){
                scanf("%d %d", &th, &row);
                connect[2*i][th] = 1;
                point[2*i][th] = 1;
            }
        }
        printf("Graph #%d:\n", times++);
        for(int i=0 ; i<(2*N-1) ; i++){
            if(i%2==0){
                for(int j=0 ; j<L ; j++){
                    if(j==0)
                        putchar('S');
                    else if(!point[i][j] && j!=L-1)
                        putchar('-');
                    else if(point[i][j] && j!=L-1)
                        putchar('O');
                    else if(j==L-1)
                        putchar('E');
                }
                putchar(10);
            }
            else{
                int flag=1;
                putchar(' ');
                while(change[i-1]>0){
                    if(!connect[i-1][flag])
                        putchar(' ');
                    else if(connect[i-1][flag])
                        putchar('|'), --change[i-1], connect[i+1][flag]=0, --change[i+1];
                    ++flag;
                }
                putchar(10);
            }
        }
    }
    return 0;
}
