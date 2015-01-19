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
int ind;
vector<string> dic;
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
    while(~scanf("%d", &ind))
        puts(dic[ind-1].c_str());
    return 0;
}
