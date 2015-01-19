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
int N, M, ti, tj, degree[100+10];
map<string, int> stint;
map<int, string> intst;
char input[51+5], binput[51+5];
bool con[100+10][100+10];
int main()
{
    int times=1;
    while(~scanf("%d", &N)){
        getchar();
        stint.clear(), intst.clear();
        memset(degree, 0, sizeof(degree));
        memset(con, false, sizeof(con));
        memset(input, '\0', sizeof(input));
        for(int i=0 ; i<N ; ++i){
            gets(input);
            stint.insert(pair<string, int>((string) input, i+1));
            intst.insert(pair<int, string>(i+1, (string) input));
            memset(input, '\0', sizeof(input));
        }
        scanf("%d", &M);
        map<string, int>::iterator it;
        for(int i=0 ; i<M ; i++){
            scanf("%s %s", input, binput);
            it = stint.find((string) input), ti = it->second;
            it = stint.find((string) binput), tj = it->second;
            if(!con[ti][tj])degree[tj]++;
            con[ti][tj] = true;
            memset(input, '\0', sizeof(input));
            memset(binput, '\0', sizeof(binput));
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ", times++);
        map<int, string>::iterator iter;
        for(int i=1, ct=0 ; i<=N ; ++i, ++ct){
            int s=1;
            while(s<=N && degree[s]!=0) ++s;
            if(s==N+1) break;
            degree[s] = -1;
            iter = intst.find(s);
            if(ct<N-1)
                printf("%s ", (iter->second).c_str());
            else
                printf("%s.\n\n", (iter->second).c_str());
            for(int j=1 ; j<=N ; j++)
                if(con[s][j])
                    degree[j]--;
        }
    }
    return 0;
}
