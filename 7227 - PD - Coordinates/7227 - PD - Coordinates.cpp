#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct point{
    int mx, my;
};

int bisearch(vector<int>, int);

int main()
{
    int n, q;
    while(~scanf("%d %d", &n, &q)){
        int tempx, tempy;
        vector<int> xarray;
        vector<int> yarray;
        for(int i=0 ; i<n ; i++){
            scanf("%d %d", &tempx, &tempy);
            xarray.push_back(tempx), yarray.push_back(tempy);
        }
        int queryX, queryY, judge=0;
        for(int i=0 ; i<q ; i++){
            scanf("%d %d", &queryX, &queryY);
            judge = bisearch(xarray, queryX);
            if(judge){
                while(yarray[judge]!=queryY)
                judge
                if(yarray[judge]!=queryY)
                    printf("No\n");
                else
                    printf("Yes\n");
            }
            else
                printf("No\n");
        }
    }
}

int bisearch(vector<int> arr, int target)
{
    int low=0, high = arr.size()-1, mid;
    while(low<high){
        mid = (low+high)/2;
        if(arr[mid]>target)
            high = mid;
        else if(arr[mid]<target)
            low = mid+1;
        else{
            while(arr[mid]==target)
                mid--;
            return mid+1;
        }
    }
    return 0;
}
