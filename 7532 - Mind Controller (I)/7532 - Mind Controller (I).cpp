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

void calculate(int);
int main()
{
    int N;
    while(~scanf("%d", &N))
        calculate(N), putchar(10);
}

void calculate(int n)
{
    if(n<=3){
        putchar(n+'0');
        return;
    }
    else
        if(n%2) calculate((n-1)/2), calculate((n+1)/2);
        else    calculate(n/2-1), calculate(n/2+1);
}
