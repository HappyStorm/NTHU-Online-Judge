#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int child, parent, visit[3000+10];
    while(~scanf("%d %d", &child, &parent)){
        char quotient[3000+10], *qstr = quotient+1;
        int start, ending;
        memset(visit, 0, sizeof(visit));
        memset(quotient, '\0', sizeof(quotient));
        printf("%d/%d = %d.", child, parent, child/parent);

        //First %.
        child = child % parent;
        //printf("\nAfter child%%parent, child= %d\n", child);

        //Record the remainder array(visit[])'s at what time be visited.
        visit[child] = 1;

        //Remainder * 10.
        child = child * 10;
        //printf("\nAfter child*10, child= %d\n", child);

        for(int i=2 ; ; i++){
            *qstr = child/parent + '0', qstr++;
            if(visit[child%parent]){
                start = visit[child%parent], ending = i;// printf("Start= %d  End= %d\n", start, ending);
                break;
            }
            visit[child%parent] = i;
            child = child % parent;
            child = child * 10;
        }
        //printf("\nQuotient= %s\n", quotient);
        int last;
        for(int i=1 ; i<ending && i<=50 ; i++){
            if(i==start)
                putchar('(');
            putchar(quotient[i]);
            last = i;
        }
        if(++last<ending)
            printf("...");
        puts(")");
    }
    return 0;
}

