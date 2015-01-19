#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

char compare[1000][20];
int main()
{
    set<string> OTAKU;
    string temp;
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0 ; i<N ; i++)
        cin >> temp, OTAKU.insert(temp);
    while(M--){
        int K, ct=0;
        scanf("%d", &K);
        for(int i=0 ; i<K ; i++){
            cin >> temp;
            if(OTAKU.find(temp)!=OTAKU.end())
                ct++;
        }
        if(ct*2>K)
            puts("Y");
        else
            puts("N");
    }
    return 0;
}
