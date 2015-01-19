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
int row, col, dir[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
struct point{
    int x, y, time;
};
point tp, origin;
queue<point> pointque;
char input[1000+5][1000+5];
int maze[1000+5][1000+5];

void putfire();
int escape();
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &row, &col), getchar();
        memset(input, '\0', sizeof(input)), memset(maze, -1, sizeof(maze));
        for(int i=0 ; i<row ; i++)
            gets(input[i]);
        point joe;
        for(int i=0 ; i<row ; i++)
            for(int j=0 ; j<col ; j++)
                if(input[i][j]=='J')
                    joe.x=i, joe.y=j, joe.time=1, maze[i][j]=-1;
                else if(input[i][j]=='F')
                    tp.x=i, tp.y=j, tp.time=0, pointque.push(tp);
                else if(input[i][j]=='.')
                    maze[i][j]=-2;
        putfire();
        pointque.push(joe);
        int time = escape();
        if(time) printf("%d\n", time);
        else puts("IMPOSSIBLE");
        while(!pointque.empty()) pointque.pop();
    }
    return 0;
}

void putfire()
{
    while(!pointque.empty()){
        origin = pointque.front(), pointque.pop();
        for(int i=0 ; i<4 ; i++){
            tp.x = origin.x+dir[i][0], tp.y = origin.y+dir[i][1], tp.time = origin.time+1;
            if(tp.x<0 || tp.x>=row || tp.y<0 || tp.y>=col || maze[tp.x][tp.y]!=-2) continue;
            maze[tp.x][tp.y] = tp.time;
            pointque.push(tp);
        }
    }
}

int escape()
{
    while(!pointque.empty()){
        origin = pointque.front();
        if(origin.x==0 || origin.x==(row-1) || origin.y==0 || origin.y==(col-1))
            return origin.time;
        pointque.pop();
        for(int i=0 ; i<4 ; i++){
            tp.x = origin.x+dir[i][0], tp.y = origin.y+dir[i][1], tp.time = origin.time+1;
            if(tp.x<0 || tp.x>=row || tp.y<0 || tp.y>=col || (maze[tp.x][tp.y]!=-2 && tp.time>maze[tp.x][tp.y])) continue;
            maze[tp.x][tp.y] = -1;
            pointque.push(tp);
        }
    }
    return 0;
}
