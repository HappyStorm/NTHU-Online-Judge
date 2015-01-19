#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
using namespace std;

double length(double, double, double, double);
double area(double, double, double, double, double, double);

int main()
{
    double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
    while(scanf("%lf %lf %lf %lf %lf %lf",
                &p1_x, &p1_y,&p2_x, &p2_y,
                &p3_x, &p3_y)!=EOF){

        //printf("P1= (%lf, %lf)\n", p1_x, p1_y);
        //printf("P2= (%lf, %lf)\n", p2_x, p2_y);
        //printf("P3= (%lf, %lf)\n", p3_x, p3_y);
        double side_12, side_23, side_13;
        side_12 = length(p1_x,p1_y,p2_x,p2_y);
        side_23 = length(p2_x,p2_y,p3_x,p3_y);
        side_13 = length(p1_x,p1_y,p3_x,p3_y);

        //printf("a= %lf\n", side_12);
        //printf("b= %lf\n", side_23);
        //printf("c= %lf\n", side_13);

        double tri_area;
        tri_area = area(p1_x,p1_y,p2_x,p2_y,p3_x,p3_y);
        //printf("Area= %lf\n", tri_area);

        double R;
        R = side_12*side_23*side_13/tri_area/4;
        //printf("R= %lf\n", R);

        double diameter = 2*R*PI;
        printf("%.2lf\n", diameter);
    }
    return 0;
}

double length(double p1_x, double p1_y, double p2_x, double p2_y)
{
    return (sqrt(pow(p1_x-p2_x,2)+pow(p1_y-p2_y,2)));
}

double area(double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y)
{
    return (fabs(p1_x*p2_y+p2_x*p3_y+p3_x*p1_y
                -p3_x*p2_y-p2_x*p1_y-p1_x*p3_y))/2;
}
