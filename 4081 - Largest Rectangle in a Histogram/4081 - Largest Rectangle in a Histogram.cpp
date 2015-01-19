#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

struct rectangle{
    long long high, index;
};

int main()
{
    int rec;
    while(~scanf("%d", &rec)){
        if(rec==0)
            break;
        long long temp, high, left, right, low, area=0, tarea;
        rectangle r;
        stack<rectangle> histogram;
        r.high = 0, r.index = 0, histogram.push(r);
        for(int i=1 ; i<=rec ; i++){
            scanf("%lld", &temp);
            if(histogram.top().high<=temp)
                r.high = temp, r.index = i, histogram.push(r);
            else{
                while(histogram.top().high>temp){
                    right = i-1;
                    high = histogram.top().high;
                    histogram.pop();
                    left = histogram.top().index;
                    low = right-left;
                    tarea = high * low;
                    area = max(area, tarea);
                }
                r.high = temp, r.index = i, histogram.push(r);
            }
        }
        right = histogram.top().index;
        while(histogram.size()>1){
            high = histogram.top().high;
            histogram.pop();
            left = histogram.top().index;
            low = right-left;
            tarea = high * low;
            area = max(area, tarea);
        }
        printf("%lld\n", area);
    }
    return 0;
}
