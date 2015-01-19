#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
//Aa Bb Cc Dd ... Yy Zz
int main()
{
    char str1[35], str2[35];
    while(EOF!=scanf("%s %s", str1, str2)){
        int i=0;
        while(str1[i] == str2[i] && i<31)
            i++;
        if(isalpha(str1[i]) && isalpha(str2[i])){
            if(tolower(str1[i])==tolower(str2[i])){
                if(str1[i] > str2[i])
                    printf("%s %s\n", str2, str1);
                else
                    printf("%s %s\n", str1, str2);
            }
            else if(tolower(str1[i])>tolower(str2[i]))
                printf("%s %s\n", str2, str1);
            else
                printf("%s %s\n", str1, str2);
        }
        else
            if(str1[i]>str2[i])
                printf("%s %s\n", str2, str1);
            else
                printf("%s %s\n", str1, str2);
    }
    return 0;
}
