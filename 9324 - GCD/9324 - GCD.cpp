#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        unsigned long long a, b, ans;
        scanf("%llu %llu", &a, &b);

        unsigned long long temp=0;
        while(true){
            if(a>b){
                temp = a%b;
                if(temp==0){
                    ans = b;
                    break;
                }
                a = temp;
            }
            else if(a<b){
                temp = b%a;
                if(temp==0){
                    ans = a;
                    break;
                }
                b = temp;
            }
            else{
                ans = a;
                break;
            }
        }
        printf("%llu\n", ans);
    }
    return 0;
}
