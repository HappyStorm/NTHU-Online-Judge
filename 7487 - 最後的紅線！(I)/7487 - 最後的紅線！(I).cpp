#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int L1, L2;
    while(EOF!=scanf("%d %d", &L1, &L2)){
        while(L1!=L2){
            if(L1>L2)
                L1 = L1 - L2;
            else
                L2 = L2 - L1;
        }
        printf("%d\n", L1);
    }
    return 0;
}
