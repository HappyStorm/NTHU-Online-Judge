#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct student{
    char name[15+5];
    double time;
    int id;
};

bool cmp(student a, student b)
{
    if(a.time!=b.time)
        return a.time<b.time;
    else
        return a.id<b.id;
}

int main()
{
    int n;
    while(~scanf("%d", &n)){
        vector<student> stulist;
        char name[20+5];
        double cputime;
        student s;
        for(int i=0 ; i<n ; i++){
            scanf("%s %lf", name, &cputime);
            strcpy(s.name, name);
            s.id = i;
            s.time = cputime;
            stulist.push_back(s);
        }
        sort(stulist.begin(), stulist.end(), cmp);
        for(int i=0 ; i<n ; i++)
            printf("%d %s %.3f\n", i+1, stulist[i].name, stulist[i].time);
    }
    return 0;
}
