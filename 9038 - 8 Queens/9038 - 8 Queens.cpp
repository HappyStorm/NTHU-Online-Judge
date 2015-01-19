#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
using namespace std;
int score[8][8], solution[8];
bool yaxis[8], diaL[15], diaR[15];
int total;

void placeQ(int, int, int);
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        memset(diaL, false, sizeof(diaL));
        memset(diaR, false, sizeof(diaR));
        memset(yaxis, false, sizeof(yaxis));
        for(int i=0 ; i<8 ; i++)
            for(int j=0 ; j<8 ; j++)
                scanf("%d", &score[i][j]);
        total=0;
        placeQ(0,0,0);
        printf("%5d\n", total);
    }
    return 0;
}

void placeQ(int cur, int layer, int chess)
{
    if(layer==8){
        if(chess==8){
            int temp=0;
                for(int i=0 ; i<8 ; i++)
                    temp+=score[solution[i]][i];
            total = max(total, temp);
            return;
        }
        return;
    }
    for(int i=0 ; i<8 ; i++){ // Run row.
        int dL = (cur+i), dR = (cur-i+15)%15;
        if(!yaxis[i] && !diaL[dL] && !diaR[dR]){
            yaxis[i] = true, diaL[dL] = true, diaR[dR] = true;
            solution[cur] = i;
            placeQ(cur+1, layer+1, chess+1);
            yaxis[i] = false, diaL[dL] = false, diaR[dR] = false;
        }
    }
}
