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
int degree[26+5];
char input[20+5];
string ti, tj;
set<char> letter;
vector<string> dic;
bool con[26+5][26+5];

int main()
{
    memset(input, '\0', sizeof(input));
    int len=0;
    while(gets(input)!=NULL){
        if(input[0]!='#'){
            len = strlen(input);
            dic.push_back((string) input);
            for(int i=0 ; i<len ; i++)
                letter.insert(input[i]);
            memset(input, '\0', sizeof(input));
        }
        else{
            memset(con, false, sizeof(con));
            memset(degree, -1, sizeof(degree));
            for(int i=0 ; i<dic.size()-1 ; i++){
                ti = dic[i], tj = dic[i+1];
                int pos = 0;
                while(ti[pos]==tj[pos]){
                    pos++;
                    if(pos>=ti.size())
                        break;
                }
                if(pos==ti.size() || pos==tj.size()) continue;
                if(!con[ti[pos]-'A'][tj[pos]-'A'])
                    degree[tj[pos]-'A']++;
                con[ti[pos]-'A'][tj[pos]-'A'] = true;
            }
            for(int i=0, ct=0 ; ; ++i, ++ct){
                int s=0;
                while(s<26 && degree[s]!=0)
                    ++s;
                if(s==26) break;
                degree[s] = -1;
                char ts = s+'A';
                if(letter.find(ts)!=letter.end())
                    putchar(s+'A');
                for(int j=0 ; j<26 ; j++)
                    if(con[s][j])
                        degree[j]--;
            }
            putchar(10);
        }
    }
    return 0;
}
