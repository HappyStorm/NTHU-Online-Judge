#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct student{
    char team[15+5];
    int solve;
    int id;
}Student[100000+10];

bool cmp(student a, student b)
{
    return a.id<b.id;
}

int main()
{
    int people;
    while(~scanf("%d", &people)){
        vector<student> student_list;
        int sol, idnum;
        char tea[15+5];
        student s;
        for(int i=0 ; i<people ; i++){
            scanf("%s %d %d", tea, &sol, &idnum);
            strcpy(s.team, tea);
            s.solve = sol;
            s.id = idnum;
            student_list.push_back(s);
        }
        sort(student_list.begin(), student_list.end(), cmp);
        for(int i=0 ; i<people ; i++)
            printf("%d %s %d\n", student_list[i].id, student_list[i].team, student_list[i].solve);
        putchar(10);
    }
    return 0;
}
