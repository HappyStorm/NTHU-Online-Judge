#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

//  abcdefghijklmnopqrstuvwxyz
//  11011020000000111000000000
//  ABCDEFGHIJKLMNOPQRSTUVWXYZ
//  12010000000000111100000000
int main()
{
    char letter[150];

    while(scanf("%s", letter)!=EOF){
        int answer=0;
        for(int i=0 ; i<strlen(letter) ; i++){
            if(letter[i]=='a' || letter[i]=='b' || letter[i]=='d' || letter[i]=='o' || letter[i]=='e'
               || letter[i]=='p' || letter[i]=='q' || letter[i]=='A' || letter[i]=='D' || letter[i]=='O'
               || letter[i]=='P' || letter[i]=='Q' || letter[i]=='R'){
                answer++;
               }
            else if(letter[i]=='g' || letter[i]=='B'){
                answer+=2;
            }
        }
        printf("%d\n", answer);
    }

    return 0;
}
