#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


int main()
{
    int coach;
    while(~scanf("%d", &coach)){
        if(coach==0)
            break;
        stack<int> station, origin;
        int input[coach];
        int temp, ct=0;
        while(scanf("%d", &temp) && temp!=0){
            input[ct++] = temp;
            if(ct==coach){
                station.push(0);
                int flag = coach, check=1;
                while(ct--){
                    if(input[ct]>station.top() && input[ct]!=flag)
                        station.push(input[ct]);
                    else if(input[ct]>station.top() && input[ct]==flag)
                        origin.push(input[ct]), flag--;
                    else if(input[ct]<station.top()){
                        if(station.top()!=flag){
                            check=0;
                            break;
                        }
                        origin.push(station.top()), station.pop(), ct++, flag--;
                    }
                }
                while(station.size()>0){
                    if(station.top())
                        origin.push(station.top());
                    station.pop();
                 }
                while(origin.size()>0)
                    origin.pop();
                if(check)
                    puts("Yes");
                else
                    puts("No");
                ct=0;
            }
        }
        putchar(10);
    }
    return 0;
}
