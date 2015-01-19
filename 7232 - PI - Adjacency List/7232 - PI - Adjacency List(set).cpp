#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;
set<int> all[100000+5];

int main()
{
    int n, m;
    while(~scanf("%d %d", &n, &m)){
        getchar();
        char input[10];
        int a, b;
        for(int i=0 ; i<n ; i++)
            all[i].clear();
        for(int i=0 ; i<m ; i++){
            scanf("%s %d %d", input, &a, &b);
            if(input[0]=='C' && input[1]=='o')
                all[a].insert(b);
            else if(input[0]=='A'){
                if(all[a].find(b)==all[a].end())
                    puts("No");
                else
                    puts("Yes");
            }
            else{
                if(all[a].find(b)==all[a].end())
                    puts("Error");
                else
                    all[a].erase(b);
            }
        }
    }
    return 0;
}
