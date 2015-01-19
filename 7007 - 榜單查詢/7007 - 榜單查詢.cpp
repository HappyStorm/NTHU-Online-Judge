#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct student{
    char name[20];
    int testid, point, rankid;
};
bool cmp(student a, student b)
{
    return a.point>b.point;
}
int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    vector<student> stulist;

    student s;
    int temp;
    char nick[20];
    for(int i=0 ; i<N ; i++){
        scanf("%s %d", nick, &temp);
        strcpy(s.name, nick);
        s.point = temp, s.testid = i;
        stulist.push_back(s);
    }
    sort(stulist.begin(), stulist.end(), cmp);

    int rankpoint=-1, same=0;
    for(int i=0, j=1 ; i<N ; i++){
        if(stulist[i].point!=rankpoint){
            stulist[i].rankid = i+1, rankpoint = stulist[i].point, same = i+1;
            //printf("Rank: %d  Name: %s  Point: %d\n", stulist[i].rankid, stulist[i].name, stulist[i].point);
        }
        while(stulist[++i].point==rankpoint){
            stulist[i].rankid = same;
            //printf("Rank: %d  Name: %s  Point: %d\n", stulist[i].rankid, stulist[i].name, stulist[i].point);
            if(i==N-1)
                break;
        }
        if(i==N-1)
            break;
        i--;
    }

    //for(int i=0 ; i<N ; i++)
    //   printf("Rank: %d  Name: %s  Point: %d\n", stulist[i].rankid, stulist[i].name, stulist[i].point);

    int query, first, exist;
    for(int i=0 ; i<Q ; i++){
        exist=0;        //           Query 1: 285
        scanf("%d", &query), printf("Query %d: ", i+1), first=1;
        for(int j=0 ; j<N ; j++){
            if(stulist[j].rankid==query && first==1)
                printf("%d\n%s\n", stulist[j].point, stulist[j].name), first=0, exist=1;
            else if(stulist[j].rankid==query && first==0)
                printf("%s\n", stulist[j].name);
        }
        if(exist==0)
            printf("null\n");
    }

    return 0;
}
