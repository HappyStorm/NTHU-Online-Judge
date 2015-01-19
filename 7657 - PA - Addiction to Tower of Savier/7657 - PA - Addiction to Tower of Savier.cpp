#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;


int st, nd, rd, th;
struct card{
    char race[20];
    int strong[83];
};
bool cmp(card a, card b)
{
    if(a.strong[st]==b.strong[st]){
        if(a.strong[nd]==b.strong[nd]){
            if(a.strong[rd]==b.strong[rd])
                return a.strong[th]>b.strong[th];
            return a.strong[rd]>b.strong[rd];
        }
        return a.strong[nd]>b.strong[nd];
    }
    return a.strong[st]>b.strong[st];
}

int main()
{
    int test, flag=1;
    scanf("%d", &test);
    while(test--){
        card c;
        char race[15];
        int num, id, hp, atk, rec, check=0;
        scanf("%d", &num);
        vector<card> bag;
        for(int i=0 ; i<num ; i++){
            memset(race, '\0', sizeof(race));
            scanf("%s %d %d %d %d", race, &id, &hp, &atk, &rec);
            c.strong['I'] = id, c.strong['H'] = hp;
            c.strong['A'] = atk, c.strong['R'] = rec;
            strcpy(c.race, race);
            bag.push_back(c);
        }
        char st1[3], nd2[3], rd3[3], th4[3];
        scanf("%s%s%s%s%s", race, st1, nd2, rd3, th4);
        st = st1[0], nd = nd2[0], rd = rd3[0], th = th4[0];
        //printf("1st=%c  2nd=%c  3rd=%c  4th=%c\n", st, nd, rd, th);
        sort(bag.begin(), bag.end(), cmp);
        printf("Case #%d\n", flag++);
        for(int i=0 ; i<num ; i++){
            if(strcmp(bag[i].race, race)==0){
                printf("%s %d %d ", bag[i].race, bag[i].strong['I'], bag[i].strong['H']);
                printf("%d %d\n", bag[i].strong['A'], bag[i].strong['R']), check++;
            }
        }
        if(!check)
            puts("Cards not found");
    }
    return 0;
}
