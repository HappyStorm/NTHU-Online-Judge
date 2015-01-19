#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int plane[4][4];
int Len(int);
void top();
void down();
void left();
void right();
int main()
{
    int test,times=1;
    scanf("%d", &test);
    while(test--){
        printf("Case #%d:\n", times++);
        for(int i=0 ; i<4 ; i++)
            for(int j=0 ; j<4 ; j++)
                scanf("%d", &plane[i][j]);
        getchar();
        char control;
        control = getchar();
        switch(control){
            case '^':{
                top();
                break;
            }
            case 'v':{
                down();
                break;
            }
            case '<':{
                left();
                break;
            }
            case '>':{
                right();
                break;
            }
            default:
                break;
        }
        for(int i=0 ; i<17 ; i++){
            if(i%4==0 && i!=16){
                puts("+----+----+----+----+");
                puts("|    |    |    |    |");
                i++;
            }
            else if(i%4==0 && i==16)
                puts("+----+----+----+----+");
            else{
                for(int j=0 ; j<4 ; j++){
                    if(plane[i/4][j]>0){
                        putchar('|');
                        printf("%4d", plane[i/4][j]);
                    }
                    else{
                        for(int k=0 ; k<5 ; k++){
                            if(k==0) putchar('|');
                            else     putchar(' ');
                        }
                    }
                }
                puts("|");
                puts("|    |    |    |    |");
                i++;
            }
        }
     }
    return 0;
}
void top()
{
    int pre=0, temp[4][4];
    memset(temp, 0, sizeof(temp));
    for(int i=0, flag=0 ; i<4 ; i++, flag=0){
        for(int j=0 ; j<4 ; j++){
            if(plane[j][i]!=0){
                if(pre!=0){
                    if(pre!=plane[j][i])
                        temp[flag++][i] = pre, pre = plane[j][i];
                    else
                        temp[flag++][i] = pre*2, pre=0;
                }
                else
                    pre = plane[j][i];
            }
        }
        if(pre!=0)
            temp[flag++][i] = pre, pre=0;
    }
    for(int i=0 ; i<4 ; i++)
        for(int j=0 ; j<4 ; j++)
            plane[i][j] = temp[i][j];
}
void down()
{
    int pre=0, temp[4][4];
    memset(temp, 0, sizeof(temp));
    for(int i=0, flag=3 ; i<4 ; i++, flag=3){
        for(int j=3 ; j>=0 ; j--){
            if(plane[j][i]!=0){
                if(pre!=0){
                    if(pre!=plane[j][i])
                        temp[flag--][i] = pre, pre = plane[j][i];
                    else
                        temp[flag--][i] = pre*2, pre=0;
                }
                else
                    pre = plane[j][i];
            }
        }
        if(pre!=0)
            temp[flag--][i] = pre, pre=0;
    }
    for(int i=0 ; i<4 ; i++)
        for(int j=0 ; j<4 ; j++)
            plane[i][j] = temp[i][j];

}
void left()
{
    int pre=0, temp[4][4];
    memset(temp, 0, sizeof(temp));
    for(int i=0, flag=0 ; i<4 ; i++, flag=0){
        for(int j=0 ; j<4 ; j++){
            if(plane[i][j]!=0){
                if(pre!=0){
                    if(pre!=plane[i][j])
                        temp[i][flag++] = pre, pre = plane[i][j];
                    else
                        temp[i][flag++] = pre*2, pre=0;
                }
                else
                    pre = plane[i][j];
            }
        }
        if(pre!=0)
            temp[i][flag++] = pre, pre=0;
    }
    for(int i=0 ; i<4 ; i++)
        for(int j=0 ; j<4 ; j++)
            plane[i][j] = temp[i][j];

}
void right()
{
    int pre=0, temp[4][4];
    memset(temp, 0, sizeof(temp));
    for(int i=0, flag=3 ; i<4 ; i++, flag=3){
        for(int j=3 ; j>=0 ; j--){
            if(plane[i][j]!=0){
                if(pre!=0){
                    if(pre!=plane[i][j])
                        temp[i][flag--] = pre, pre = plane[i][j];
                    else
                        temp[i][flag--] = pre*2, pre=0;
                }
                else
                    pre = plane[i][j];
            }
        }
        if(pre!=0)
            temp[i][flag--] = pre, pre=0;
    }
    for(int i=0 ; i<4 ; i++)
        for(int j=0 ; j<4 ; j++)
            plane[i][j] = temp[i][j];
}
int Len(int n)
{
    int time=1;
    while(n/10>0)
        time++, n/=10;
    return time;
}
