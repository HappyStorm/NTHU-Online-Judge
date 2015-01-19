#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, p;
    while(scanf("%d %d %d", &n, &k, &p)){
        int toy[100000]={0};
        vector<int> playcar;
        for(int i=0 ; i<p ; i++){
            int temp;
            scanf("%d", &temp);
            toy[temp]++;
            playcar.push_back(temp);
        }



    }


    return 0;
}
