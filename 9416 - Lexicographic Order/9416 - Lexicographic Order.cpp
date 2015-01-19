#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int people;
    while(EOF!=scanf("%d", &people)){
        vector<string> namelist;
        if(people==0)
            break;
        for(int i=0 ; i<people ; i++){
            char temp[51];
            scanf("%s", temp);
            namelist.push_back(temp);
        }
        sort(namelist.begin(), namelist.end());
        for(int i=0 ; i<people ; i++)
            cout << namelist.at(i) << endl;
        printf("\n");
    }
    return 0;
}
