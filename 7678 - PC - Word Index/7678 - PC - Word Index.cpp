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
char input[10];
vector<string> dic;
map<string, int> all;
bool cmp(string a, string b)
{
    if(a.size()==b.size())
        return a<b;
    return a.size()<b.size();
}
int main()
{
    char temp[5+5];
    memset(temp, '\0', sizeof(temp));
    for(int i=0 ; i<26 ; i++){
        temp[0] = i+'a';
        for(int j=i+1 ; j<26 ; j++){
            temp[1] = j+'a';
            for(int k=j+1 ; k<26 ; k++){
                temp[2] = k+'a';
                for(int l=k+1 ; l<26 ; l++){
                    temp[3] = l+'a';
                    for(int m=l+1 ; m<26 ; m++){
                        temp[4] = m+'a', dic.push_back((string)temp);
                    }
                    temp[4] = '\0', dic.push_back((string)temp);
                }
                temp[3] = '\0', dic.push_back((string)temp);
            }
            temp[2] = '\0', dic.push_back((string)temp);
        }
        temp[1] = '\0', dic.push_back((string)temp);
    }
    sort(dic.begin(), dic.end(), cmp);
    for(int i=0 ; i<dic.size() ; i++)
        all.insert(pair<string, int>(dic[i], i+1));
    map<string, int>::iterator iter;
    memset(input, '\0', sizeof(input));
    while(gets(input)!=NULL){
        iter = all.find((string)input);
        if(iter!=all.end())
            printf("%d\n", iter->second);
        else
            puts("0");
        memset(input, '\0', sizeof(input));
    }
    return 0;
}
