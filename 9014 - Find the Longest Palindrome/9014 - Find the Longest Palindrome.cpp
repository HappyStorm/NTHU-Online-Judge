#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char input[1000];
    while(gets(input)!=NULL){
        int longest_odd=0, longest_even=0;
        int length = strlen(input);
        char ans_odd[1000]={0}, ans_even[1000]={0}, input_for_even[2000]={0};

        for(int i=0 ; i<length ; i++){
            input_for_even[i++] = input[i];
            input_for_even[i]=' ';
        }
        //printf("OK\n");
        //Total numbers = odd.
        int ct_odd=0, flag_odd=0;
        for(int i=0 ; i<length ; i++){
            for(int j=0 ; j<=i ; j++){
                if(input[i-j]==input[i+j])
                    ct_odd+=2;
                else if(input[i-j]!=input[i+j] && ct_odd>0){
                    if(ct_odd>longest_odd)
                        longest_odd = ct_odd+1, strncpy(ans_odd, input+i-j, longest_odd);
                    ct_odd=0;
                    break;
                }
                flag_odd = j;
            }
            if(ct_odd>longest_odd){
                longest_odd = ct_odd+1;
                strncpy(ans_odd, input+i-flag_odd, longest_odd);
                ct_odd=0;
            }
        }
        //Total numbers = even.
        int ct_even=0, length_even = strlen(input_for_even), flag_even=0;
        for(int i=1 ; i<length_even ; i+=2){
            for(int j=0 ; j<i ; j+=2){
                if(input_for_even[i-j-1]==input_for_even[i+j+1])
                    ct_even+=2;
                else if(input_for_even[i-j-1]!=input_for_even[i+j+1] && ct_even>0){
                    if(ct_even>longest_even){
                        longest_even = ct_even;
                        strncpy(ans_even, input+i-j, longest_even);
                    }
                    ct_even=0;
                    break;
                }
                flag_even = j-2;
            }
            if(ct_even>longest_even){
                longest_even = ct_even, strncpy(ans_even, input+i-flag_even, longest_even);
                ct_even=0;
            }
        }
        if(longest_odd>longest_even)
            printf("Odd Big: %s\n", ans_odd);
        else if(longest_odd<longest_even)
            printf("Even Big:%s\n", ans_even);
        else if(longest_even==0 || longest_odd==0)
            printf("NO: %c\n", input[0]);
    }
    return 0;
}
