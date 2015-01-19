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
int m, n, alloil;
char grid[100+5][100+5];
bool oil[100+5][100+5];

void deposit(int, int);
int main()
{
    memset(grid, '\0', sizeof(grid));
    memset(oil, false, sizeof(oil));
    while(~scanf("%d %d", &m, &n) && m){
        getchar();
        for(int i=0 ; i<m ; i++)
            gets(grid[i]);
        alloil=0;
        for(int i=0 ; i<m ; i++)
            for(int j=0 ; j<n ; j++)
                if(grid[i][j]=='@') alloil++;
        int oilcount=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]=='@' && !oil[i][j])
                    oilcount++, deposit(i,j);
                if(alloil==0) break;
            }
            if(alloil==0) break;
        }
        printf("%d\n", oilcount);
        memset(grid, '\0', sizeof(grid));
        memset(oil, false, sizeof(oil));
    }
    return 0;
}
void deposit(int x, int y)
{
    if(alloil==0 || x<0 || x>=m || y<0 || y>=n)
        return;
    if(grid[x][y]=='@' && !oil[x][y]){
        oil[x][y] = true, alloil--;
        deposit(x-1,y-1), deposit(x,y-1), deposit(x+1,y-1);
        deposit(x-1,y)  ,                 deposit(x+1,y);
        deposit(x-1,y+1), deposit(x,y+1), deposit(x+1,y+1);
    }
}
