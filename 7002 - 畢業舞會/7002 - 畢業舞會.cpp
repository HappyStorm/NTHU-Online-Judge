#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int bi_find(int*, int, int);
int flag=0;

int main()
{
    int lady, possible, sh=0, ta=0;

    scanf("%d", &lady);
    int* ladies = (int*) malloc(lady * sizeof(int));
    int i=0;
    while(i<lady)
        scanf("%d", &ladies[i]), i++;

    scanf("%d", &possible);
    int* myheight = (int*) malloc(possible * sizeof(int));
    int j=0;
    while(j<possible){
        scanf("%d", &myheight[j]), j++;
    }


    for(int k=0; k<possible ; k++){
        if(flag==0){
            int locate = bi_find(ladies, myheight[k], lady);
            sh = ladies[locate];
            ta = ladies[locate+1];
        }
        else{
            int locate = bi_find(ladies, myheight[k], lady);
            sh = ladies[locate-1];
            ta = ladies[locate+1];
        }

        if(sh==0 && ta==0)
            printf("X X\n");
        else if(sh==0 && ta!=0)
            printf("X %d\n", ta);
        else if(sh!=0 && ta==0)
            printf("%d X\n", sh);
        else
            printf("%d %d\n", sh, ta);
        sh=0, ta=0;
    }
    free(ladies);
    free(myheight);
    return 0;
}

int bi_find(int* ladies, int tall, int lady)
{
    int low=0, high = lady-1;
    while(low<high){
        int mid = (low+high)/2;

        if(ladies[mid]==tall){
            flag = 1;
            return mid;
        }
        else if(ladies[mid]<tall)
            low = mid+1;
        else
            high = mid-1;
        }
    return low;
}
