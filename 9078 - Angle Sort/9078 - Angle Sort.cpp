#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define PI 3.14159265
using namespace std;

typedef struct point{
    int id;
    double x, y, angle;
}Point;

bool cmp(Point a, Point b)
{
    return a.angle<b.angle;
}

int main()
{
    int N;
    while(~scanf("%d", &N)){
        double ox, oy;
        scanf("%lf %lf", &ox, &oy);
        Point temp;
        vector<Point> point_list;
        double tx, ty, longside, tangle, xside, yside;
        for(int i=0 ; i<N ; i++){
            scanf("%lf %lf", &tx, &ty);
            xside = tx-ox, yside = ty-oy;
            longside = sqrt(xside*xside+yside*yside);
            tangle = asin(yside/longside)*180/PI;
            if(tx<ox && ty>oy)              //Section 2.
                tangle = 180 - tangle;      // printf("Sec 2.\n");
            else if(tx<ox && ty<oy)         //Section 3.
                tangle = -tangle + 180;     // printf("Sec 3.\n");
            else if(tx>ox && ty<oy)         //Section 4.
                tangle = 360 - (-tangle);   // printf("Sec 4.\n");
            else if(tx>ox && (ty-oy)<1e-8)  //At the +x axis.
                tangle = 0;
            else if(tx<ox && (ty-oy)<1e-8)  //At the -x axis.
                tangle = 180;
            else if((tx-ox)<1e-8 && ty>oy)  //At the +y axis.
                tangle = 90;
            else if((tx-ox)<1e-8 && ty<oy)  //At the -y axis.
                tangle = 270;
            temp.x = tx, temp.y = ty, temp.id = i+1, temp.angle = tangle;
            point_list.push_back(temp);
        }
        sort(point_list.begin(), point_list.end(), cmp);
        for(int i=0 ; i<N ; i++)
            if(i!=N-1)
                printf("%d ", point_list[i].id);
            else
                printf("%d\n", point_list[i].id);
    }
}
