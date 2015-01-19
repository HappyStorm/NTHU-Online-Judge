#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
double cTof(int);
double fToc(double);

int main()
{
    int num;
    scanf("%d ", &num);

    for(int i=0 ; i<num ; i++){
        int c, dif;
        double df, f, temp, answer;
        scanf("%d %d", &c, &dif);
        df = dif;
        f = cTof(c);
        temp = (df + f);
        answer = fToc(temp);
        printf("Case %d: %.2f\n", i+1, answer);
    }
    return 0;
}

double cTof(int c)
{
    double tempc=c;
    return 9*tempc/5 + 32;
}
double fToc(double f)
{
    return (5*f-160)/9;
}
