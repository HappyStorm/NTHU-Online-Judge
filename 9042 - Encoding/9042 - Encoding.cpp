#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

char input[1000000+10];
char temp [1000000+10];
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int way, k;
        scanf("%d %d", &way, &k);
        memset(input, '\0', sizeof(input)), memset(temp, '\0', sizeof(temp));
        scanf("%s", input);
        int length = strlen(input), shift = k%26;
        if(way==1){//65='A'~81'Z'.
            for(int i=length-1 ; i>=0 ; i--)
                temp[i] = input[length-i-1];
            for(int i=0 ; i<length ; i++)
                if((temp[i]+shift)>90)
                    putchar((temp[i]+shift)-26);
                else
                    putchar((temp[i]+shift));
            putchar(10);
        }
        else{
            for(int i=length-1 ; i>=0 ; i--)
                temp[i] = input[length-i-1];
            for(int i=0 ; i<length ; i++)
                if((temp[i]-shift)<65)
                    putchar((temp[i]-shift)+26);
                else
                    putchar((temp[i]-shift));
            putchar(10);
        }
    }
    return 0;
}
