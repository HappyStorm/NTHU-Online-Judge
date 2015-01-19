#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class people
{
    public:
        people(char*);
        char name[15];
};
people::people(char* n)
{
    int length = strlen(n);
    for(int i=0 ; i<15 ; i++)
        name[i]='\0';
    for(int i=0 ; i<length ; i++)
        name[i] = n[i];
}
int main()
{
    int nums;
    while(EOF!=scanf("%d", &nums)){
        vector<people> grade[100+5];
        while(nums--){
            int score;
            char name[15];
            scanf("%s %d", name, &score);
            grade[score].push_back(name);
        }
        for(int i=0 ; i<105 ; i++){
            for(int j=0 ; j<grade[i].size() ; j++)
                printf("%s %d\n", grade[i][j].name, i);
        }
    }
    return 0;
}
