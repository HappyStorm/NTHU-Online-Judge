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
/*bool cmp(people a, people b)
{
    if(a.grade<b.grade)
        return a.grade<b.grade;
    else if(a.grade>b.grade)
        return a.grade<b.grade;
    else{
        if(a.flag>b.flag)
            return a.flag<b.flag;
        else
            return a.flag>b.flag;
    }
}*/
//void Mergesort(int, vector<people>);
//void my_merge(int, int, vector<people>, vector<people>, vector<people>);

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
        //sort(peoples.begin(), peoples.end(), cmp);
        //Mergesort(nums, peoples);

        for(int i=0 ; i<100 ; i++){
            for(int j=0 ; j<grade[i].size() ; j++)
                printf("%s %d\n", grade[i][j].name, i);
        }
    }
    return 0;
}

/*void Mergesort(int num, vector<people> data)
{
    if(num==1)
        return;
    int Lhs = num/2, Rhs = num - Lhs;
    vector<people> left;
    vector<people> right;

    for(int i=0 ; i<Lhs ; i++)
        left.push_back(data[i]);
    for(int i=0 ; i<Rhs ; i++)
        right.push_back(data[Lhs+i]);
    Mergesort(Lhs, left);
    Mergesort(Rhs, right);
    my_merge(Lhs, Rhs, left, right, data);
}
void my_merge(int Lhs, int Rhs, vector<people> left, vector<people> right, vector<people> data)
{
    int index=0, l=0, r=0;
    while(l<Lhs && r<Rhs){
        if(left[l].grade>right[r].grade)
            data[index++] = right[r++];
        else
            data[index++] = left[l++];
    }
    while(l<Lhs)
        data[index++] = left[l++];
    while(r<Rhs)
        data[index++] = right[r++];
}*/
