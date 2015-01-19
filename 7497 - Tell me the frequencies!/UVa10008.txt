#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char input[1050];
    int flag=0;
    while(gets(input)!=NULL){
        if(flag)
            printf("\n");
        int sym;
        int data[126]={0};

        int length = strlen(input), ct=0;
        for(int i=0 ; i<length ; i++)
            input[i] = toupper(input[i]);

        for(int i=0 ; i<length ; i++){
            sym = input[i];
            data[sym]++, ct++;
        }

        for(int i=1 ; i<ct ; i++){
            for(int j=65 ; j<=91 ; j++){
                if(data[j]==i)
                    printf("%c %d\n", j, i);
            }
        }
        flag++;
    }
    return 0;
}
