#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string num1, num2, sum;
    while(cin>>num1>>num2){
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int num1_length = num1.size();
        int num2_length = num2.size();

        long long times=0, temp=0, i=0;
        while(i<num1_length && i<num2_length){
            if((num1.at(i)-'0'+num2.at(i)-'0'+temp)>=10)
                temp=(num1.at(i)-'0'+num2.at(i)-'0'+temp)/10, times+=temp;
            else
                temp=0;
            i++;
        }

        if(num1_length==i){
            while(i<num2_length){
                if(num2.at(i)-'0'+temp>=10)
                    temp=(num2.at(i)-'0'+temp)/10, times+=temp;
                else
                    temp=0;
                i++;
            }
        }
        else if(num2_length==i){
            while(i<num1_length){
                if(num1.at(i)-'0'+temp>=10)
                    temp=(num1.at(i)-'0'+temp)/10, times+=temp;
                else
                    temp=0;
                i++;
            }
        }
        printf("%d\n", times);
    }
    return 0;
}
