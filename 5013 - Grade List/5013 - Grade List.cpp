#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int exam, hw, flag=1;
    char garbage[1000+5];
    while(~scanf("%d %d", &exam, &hw)){
        gets(garbage);
        printf("Student #%d: %d\n", flag++, exam+hw);
    }
    return 0;
}
