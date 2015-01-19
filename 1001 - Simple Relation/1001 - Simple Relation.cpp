#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main()
{
    int num_Data, con=0;
    scanf("%d", &num_Data);

    while(con<num_Data){
        int length;
        scanf("%d", &length);
        int *A = (int*) malloc(length * sizeof(int));
        int *B = (int*) malloc(length * sizeof(int));
        int *C = (int*) malloc(length * sizeof(int));

        for(int i=0; i<length ; i++)
            scanf("%d", A+i);
        for(int i=0; i<length ; i++)
            scanf("%d", B+i);

        char O[10000];
        scanf("%s", O);

        int bp=0, cp=0, flag=0, position=0, len=strlen(O);
        for(int i=0; i<len; i++){
            if(O[i]=='1'){
                if(flag==0)
                    flag++;
                else if(flag==1){
                    bp=position;
                    position=0;
                    flag++;
                }
                else if(flag==2){
                    cp=position;
                    break;
                }
            }
            else if(O[i]=='0')
                position++;
        }

        for(int i=0 ; i<length ; i++)
            C[(i+cp)%length] = A[i] + B[(i+bp)%length];
        for(int i=0 ; i<length ; i++){
            if(i<=length-2)
                printf("%d ", *(C+i));
            else if(i==length-1)
                printf("%d\n", *(C+i));
        }
        free(A);
        free(B);
        free(C);
        con++;
    }
    return 0;
}
