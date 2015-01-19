#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void Mergesort(int, int*);
void my_merge(int, int, int*, int*, int*);
int my_atoi(int, char*);
long long ans=0;
int main()
{
    int nums[100005]={0};
    char input[100000]={0};
    while(NULL!=gets(input)){
        char *temp;
        int ct=0, ctnum=0, flag=0, length = strlen(input);

        /*temp = strtok(input, " ");
        while(temp!=NULL)
            nums[ctnum++] = atoi(temp), temp = strtok(NULL, " ");*/

        for(int i=0 ; i<length ; i++){
            if(input[i]!=' ' && flag==0 && i!=length-1){
                temp[ct++] = input[i];
                flag=1;                    printf("1.now: %c\n", input[i]);
            }
            else if(input[i]!=' ' && flag==1 && i!=length-1){
                temp[ct++] = input[i];     printf("2.now: %c\n", input[i]);
            }
            else if(input[i]==' ' && flag==1 && i!=length-1){
                nums[ctnum++] = my_atoi(ct, temp);
                for(int j=0 ; j<ct ; j++)
                    temp[j]='\0';
                ct=0, flag=0;              printf("3.now: %c\n", input[i]);
            }
            else if(input[i]!=' ' && i==length-1 && flag==1){
                temp[ct++] = input[i];
                nums[ctnum++] = my_atoi(ct, temp);
                for(int j=0 ; j<ct ; j++)
                    temp[j]='\0';
                 ct=0, flag=0;             printf("4.now: %c\n", input[i]);
            }
            else if(input[i]!=' ' && i==length-1 && flag==0){
                nums[ctnum++] = input[i]-'0';
            }
        }
        ans=0;
        Mergesort(ctnum, nums);
        /*for(int i=0 ; i<ctnum ; i++)
            printf("%d\n", nums[i]);*/
        printf("%lld\n", ans);
    }
    return 0;
}

int my_atoi(int len, char* input)
{
    char temp[20];
    for(int i=0 ; i<len ; i++)
        temp[i] = input[i];
    return atoi(temp);
}

void Mergesort(int num, int* data)
{
    if(num==1)
        return;
    int Lhs = num/2;
    int Rhs = num-Lhs;
    int left[Lhs], right[Rhs];

    //Copy data to local array.(to left[] and right[])
    for(int i=0 ; i<Lhs ; i++)
        left[i] = data[i];
    for(int i=0 ; i<Rhs ; i++)
        right[i] = data[i+Lhs];
    //After copy, then cut the array until the length of array = 1.
    Mergesort(Lhs, left), Mergesort(Rhs, right);
    //Then, start to merge the arrays.
    my_merge(Lhs, Rhs, left, right, data);
}
void my_merge(int L_max, int R_max, int* left, int* right, int* data)
{
    int index=0, l=0, r=0;
    //While these two arrays are not out of its bound.
    while(l<L_max && r<R_max){
        if(left[l]<=right[r])
            data[index++] = left[l++];
        else
            data[index++] = right[r++], ans+=(L_max-l);
    }
    while(l<L_max)
        data[index++] = left[l++];
    while(r<R_max)
        data[index++] = right[r++];
}
